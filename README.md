# Hospital Triage & Queue System (C++)

Priority-based patient triage system written in C++ for a Data Structures course[cite: 4, 5]. Patients are routed by severity (`Emergency`, `Critical`, `General`) and dispatched to doctors in order rather than flat first-come-first-served[cite: 6, 9].

## How It's Structured
- `include/` — Class and template declarations (`Patient.h`, `Node.h`, `Queue.h`, `HospitalSystem.h`)[cite: 4]
- `src/` — Implementations and entry point (`Patient.cpp`, `Node.cpp`, `Queue.cpp`, `HospitalSystem.cpp`, `main.cpp`)[cite: 4]
- `DS Project.sln` — Visual Studio solution[cite: 9]

## What It Does
- Logs incoming patients with a triage level (`Emergency`, `Critical`, `General`)[cite: 9]
- Tracks waiting patients across priority queues[cite: 9]
- Pulls the next highest-priority patient when a doctor becomes available[cite: 9]

## Running It
Open `DS Project.sln` in Visual Studio and run, or build directly from the command line:

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o hospital_system
./hospital_system
