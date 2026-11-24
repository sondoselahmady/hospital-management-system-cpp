# Hospital Triage & Queue System (C++)

Priority-based patient triage system written in C++ for a Data Structures course. Patients are routed by severity (`Emergency`, `Critical`, `General`) and dispatched to doctors in order rather than flat first-come-first-served.

## How It's Structured
- `include/` — Class and template declarations (`Patient.h`, `Node.h`, `Queue.h`, `HospitalSystem.h`)
- `src/` — Implementations and entry point (`Patient.cpp`, `Node.cpp`, `Queue.cpp`, `HospitalSystem.cpp`, `main.cpp`)
- `DS Project.sln` — Visual Studio solution

## What It Does
- Logs incoming patients with a triage level (`Emergency`, `Critical`, `General`)
- Tracks waiting patients across priority queues
- Pulls the next highest-priority patient when a doctor becomes available

## Running It
Open `DS Project.sln` in Visual Studio and run, or build directly from the command line:

```bash
g++ -std=c++17 src/*.cpp -o hospital_system
./hospital_system
```

## What I Learned

- Implementing priority queues from scratch with linked lists
- Separating declarations (include/) from implementations (src/) in a multi-file C++ project
