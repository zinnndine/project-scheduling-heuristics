# Two-Machine Scheduling Heuristics (F2‖Cmax & J2‖Cmax & O2||Cmax)

Implementation of classic exact and heuristic algorithms for two-machine scheduling problems, focusing on makespan minimization (Cmax).

---

## Problem Statement

Scheduling problems arise in manufacturing and production systems where a set of jobs must be processed on machines under specific constraints.  
This project focuses on **two-machine flow shop and job shop and open shop scheduling problems**, a well-studied class in operations research, with the objective of minimizing the **makespan (Cmax)**.

---

## Scope and Assumptions

- Exactly **two machines**
- Deterministic processing times
- No preemption
- All jobs are available at time zero
- Objective: minimize makespan (Cmax)


---

## Algorithms Implemented

- **Johnson’s Rule** — optimal algorithm for F2‖Cmax
- **Jackson’s Rule** — extension for J2‖Cmax
- **Gonzalez–Sahni heuristic** for O2‖Cmax
- **LAPT heuristic** for O2‖Cmax
- **GARD heuristic** for O2‖Cmax

---

## Implementation Details

- Language: **C++**
- Standard library only (no external dependencies)
---


## How to Compile and Run (Linux)


```bash
cd flow_shop
g++ johnson.cpp -o johnson
./johnson
```

```bash
cd job_shop
g++ jackson.cpp -o jackson
./jackson
```

```bash

cd open_shop
g++ "Gard Lapt Gonzalez .cpp" -o gonzalez
./gonzalez
```
