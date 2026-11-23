#include "../include/HospitalSystem.h"
#include <iostream>

using namespace std;

void HospitalSystem::run() {
    int choice;
    while (true) {
        cout << "\n**** Hospital Management System ****\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Queues\n";
        cout << "3. Assign Doctor to a Patient\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            int priorityVal;

            cout << "Enter Patient's ID: ";
            cin >> id;
            cout << "Enter Patient's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Patient's Priority (0: General, 1: Critical, 2: Emergency): ";
            cin >> priorityVal;

            Priority p;
            switch (priorityVal) {
            case 2: p = Priority::Emergency; break;
            case 1: p = Priority::Critical; break;
            default: p = Priority::General; break;
            }

            Patient newPatient(id, name, p);
            addPatient(newPatient);
        }

        else if (choice == 2) {
            displayQueues();
        }
        else if (choice == 3) {
            assignDoctorToPatient();
        }
        else if (choice == 4) {
            cout << "Thank You! Stay Safe\n... Exiting ...\n";
            break;
        }
        else {
            cout << "Invalid Choice. Enter a Number between [1-4]\n";
        }
    }
}

// Default constructor
HospitalSystem::HospitalSystem() {

}

// Admit a patient into the appropriate priority queue
void HospitalSystem::addPatient(const Patient& p) {
    switch (p.getPriority()) {
    case Priority::Emergency:
        emergencyQueue.enqueue(p);
        break;
    case Priority::Critical:
        criticalQueue.enqueue(p);
        break;
    case Priority::General:
        generalQueue.enqueue(p);
        break;
    }
}

// Display current queue contents
void HospitalSystem::displayQueues() const {
    if (emergencyQueue.isEmpty() && criticalQueue.isEmpty() && generalQueue.isEmpty())
        cout << "No Patients in the Queues\n";
    else
    {
        cout << "\n<<<<< Emergency Patients >>>>>" << endl;
        if (emergencyQueue.isEmpty())
            cout << "No Patients in this Queue\n";
        else
            emergencyQueue.print();

        cout << "\n<<<<< Critical Patients >>>>>" << endl;
        if (criticalQueue.isEmpty())
            cout << "No Patients in this Queue\n";
        else
            criticalQueue.print();

        cout << "\n<<<<< General Patients >>>>>" << endl;
        if (generalQueue.isEmpty())
            cout << "No Patients in this Queue\n";
        else
            generalQueue.print();
    }
}

void HospitalSystem::assignDoctorToPatient() {
    if (!emergencyQueue.isEmpty()) {
        Patient p = emergencyQueue.front();
        emergencyQueue.dequeue();
        cout << "\nA Doctor is Assigned to \"Emergency\" Patient:\n";
        p.printPatient();
    }
    else if (!criticalQueue.isEmpty()) {
        Patient p = criticalQueue.front();
        criticalQueue.dequeue();
        cout << "\nA Doctor is Assigned to \"Critical\" Patient:\n";
        p.printPatient();
    }
    else if (!generalQueue.isEmpty()) {
        Patient p = generalQueue.front();
        generalQueue.dequeue();
        cout << "\nA Doctor is Assigned to \"General\" Patient:\n";
        p.printPatient();
    }
    else {
        cout << "\nNo Patients in the Queue.\n";
    }
}