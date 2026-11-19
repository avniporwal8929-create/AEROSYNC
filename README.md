# AEROSYNC – Air Traffic Control Simulation
<img width="959" height="563" alt="image" src="https://github.com/user-attachments/assets/1addbc4c-f584-4654-a1ee-7612339eca07" />


**A Linux-based Air Traffic Control Simulation using C Programming and Operating Systems Concepts.**

AEROSYNC is a menu-driven simulation project developed to demonstrate fundamental Operating Systems concepts through an Air Traffic Control (ATC) environment.

The project represents aircraft as processes and an ATC controller that coordinates their execution, receives communication messages, handles process-related signals, and performs system monitoring.

---

## Project Overview

AEROSYNC demonstrates how Linux process management and system-level programming concepts can be applied to a simulated air traffic control environment.

The project brings together multiple Operating Systems concepts in one interactive terminal-based application.

## Key Features

- **Process Management:** Creates and manages aircraft processes using `fork()` and `wait()`.
- **Inter-Process Communication (IPC):** Demonstrates communication between aircraft processes and the ATC controller.
- **Signal Handling:** Demonstrates signal handling, including `SIGCHLD` notifications when child processes terminate.
- **System Monitoring:** Uses a Bash script to execute monitoring tasks.
- **Monitoring Logs:** Displays saved monitoring information.
- **Flight Report:** Displays the generated flight execution report.
- **Interactive Menu:** Provides a simple menu-driven interface to access all project modules.

## Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Core system programming |
| Linux / Ubuntu | Development and execution environment |
| GCC | C compiler |
| Bash Scripting | System monitoring |
| Makefile | Build and execution automation |
| Git & GitHub | Version control and project hosting |

## 📂 Project Structure

```text
AEROSYNC/
│
├── src/
│   ├── main.c
│   ├── ipc.c
│   ├── signals.c
│   └── menu.c
│
├── include/
│   └── atc.h
│
├── scripts/
│   └── monitor.sh
│
├── logs/
│   └── monitor.log
│
├── reports/
│   └── flight_report.txt
│
├── Makefile
├── README.md
└── .gitignore
```

## Installation and Execution

### 1. Clone the repository

```bash
git clone https://github.com/avniporwal8929-create/AEROSYNC.git
```

### 2. Navigate to the project directory

```bash
cd AEROSYNC
```

### 3. Build the project

```bash
make
```

### 4. Launch the interactive menu

```bash
make menu
```

**Requirements:**
- Ubuntu or another compatible Linux environment
- GCC compiler
- GNU Make
- Bash shell

## Available Modules

| Option | Module | Description |
|---|---|---|
| 1 | Process Management | Demonstrates aircraft process creation and execution |
| 2 | IPC Communication | Displays communication between aircraft and controller |
| 3 | Signal Handling | Demonstrates process signals and child-process notifications |
| 4 | System Monitoring | Executes the monitoring script |
| 5 | View Monitoring Logs | Displays monitoring logs |
| 6 | View Flight Report | Displays the generated flight report |
| 7 | Exit | Shuts down the application |

## Operating Systems Concepts Demonstrated

- Process Creation using `fork()`
- Process Synchronization using `wait()`
- Process Identification using `getpid()`
- Inter-Process Communication
- Signal Handling using `SIGCHLD`
- Linux Shell Scripting
- File Handling and Logging
- Build Automation using Makefile

##  Project Objective

The objective of AEROSYNC is to gain practical experience with Linux system programming and understand how processes can be created, coordinated, communicate with one another, and respond to operating-system events.

##  Future Enhancements

- Graphical air traffic control dashboard
- Real-time aircraft status visualization
- Enhanced monitoring and reporting
- More advanced process coordination
- Interactive simulation controls

## Disclaimer

AEROSYNC is an educational Operating Systems simulation project. It is not intended for real-world air traffic control or aviation operations.

## Author

**Avni Porwal**

B.Tech – Computer Science and Engineering

GitHub: [@avniporwal8929-create](https://github.com/avniporwal8929-create)

---

If you find this project interesting, consider starring the repository!

**AEROSYNC – Simulating the Systems Behind Air Traffic Control.**
