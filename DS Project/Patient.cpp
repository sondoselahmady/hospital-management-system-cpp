#include "Patient.h"
#include <iostream>
using namespace std;

Patient::Patient() {
    id = 0;
    name = "Unknown";
    priority = Priority::General;
}

Patient::Patient(int i, string n, Priority p) {
    id = i;
    name = n;
    priority = p;
}

Priority Patient::getPriority() const {
    return priority;
}

void Patient::printPatient() const {
    string prio;
    switch (priority) {
    case Priority::Emergency: prio = "Emergency"; break;
    case Priority::Critical:  prio = "Critical";  break;
    case Priority::General:   prio = "General";   break;
    }
    cout << "Name: " << name << " | ID: " << id << " | Priority: " << prio << endl;
}