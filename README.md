# AEROSYNC – Air Traffic Control System

## 1. Project Overview

AEROSYNC is a Unix-based Air Traffic Control simulation system developed using C programming and Shell Scripting.

The project demonstrates important Unix operating system concepts through aircraft monitoring and execution of independent modules.

## 2. Project Objectives

- Demonstrate process creation and management.
- Implement Inter-Process Communication (IPC).
- Demonstrate signal handling in Unix.
- Automate monitoring using Shell Scripting.
- Generate execution logs and flight reports.

## 3. Technologies Used

- C Programming
- GCC Compiler
- Ubuntu Linux
- Unix System Calls
- Bash Shell Scripting
- Makefile

## 4. Project Modules

### Module 1: Process Management
File: src/main.c

Demonstrates process management using Unix system calls such as fork() and wait().

### Module 2: Inter-Process Communication
File: src/ipc.c

Demonstrates communication between processes using pipes.

### Module 3: Signal Handling
File: src/signals.c

Demonstrates handling of Unix signals.

### Module 4: Monitoring Script
File: scripts/monitor.sh

Automates the monitoring process and generates execution records.

## 5. Aircraft Monitored

1. AI101
2. BA207
3. SQ412

## 6. Project Structure

AEROSYNC/
├── src/
│   ├── main.c
│   ├── ipc.c
│   └── signals.c
├── include/
│   └── atc.h
├── scripts/
│   └── monitor.sh
├── logs/
│   └── monitor.log
├── reports/
│   └── flight_report.txt
├── Makefile
└── README.md

## 7. Compilation

Open the terminal inside the project directory and execute:

    make

This compiles all three C modules using GCC.

## 8. Execution

To compile and execute the monitoring script:

    make monitor

To remove compiled executable files:

    make clean

## 9. Output and Reports

Execution logs are stored in:

    logs/monitor.log

The generated flight report is stored in:

    reports/flight_report.txt

The flight report contains aircraft information and the execution status of all three main modules.

## 10. Conclusion

AEROSYNC demonstrates the practical implementation of Unix operating system concepts, including process management, inter-process communication, signal handling, shell scripting, and build automation.

The project provides a simulation of aircraft monitoring through independent C modules and automated reporting.

