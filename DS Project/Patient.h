#pragma once
#include <string>

enum class Priority { General, Critical, Emergency };

class Patient {
public:
    int id;
    std::string name;
    Priority priority;

    Patient();
    Patient(int i, std::string n, Priority p);
    Priority getPriority() const;
    void printPatient() const;
};