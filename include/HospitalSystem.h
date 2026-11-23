#pragma once
#include "Queue.h"
#include "Patient.h"


class HospitalSystem {
private:


    Queue<Patient> emergencyQueue;
    Queue<Patient> criticalQueue;
    Queue<Patient> generalQueue;

public:
    HospitalSystem();
    void run();
    void assignDoctorToPatient();

    void addPatient(const Patient& p);

    void displayQueues() const;
};