# OS Simulation Project: Process Scheduling, Memory Management, and I/O

## Overview
This project is a simple simulation of **Operating System concepts** including **process scheduling**, **memory management**, and **I/O management**, all implemented in **C**. It is ideal for beginners and computer science students who want to understand how an OS works at a fundamental level.

The simulation demonstrates:
- **Process Scheduling** using the **Round-Robin Algorithm**.
- **Memory Management** using the **First-Fit Allocation** technique.
- **I/O Management**, simulating processes that move between states like **READY**, **WAITING**, and **TERMINATED**.

## Concepts Used
### 1. Process Scheduling
The **Round-Robin** scheduling algorithm is implemented where each process is given a fixed time slice to execute. If a process does not complete within its time slice, it moves back to the **READY** state.

### 2. Memory Management
Memory is allocated using the **First-Fit** algorithm, where processes are assigned the first available memory block that fits their requirements. The memory is released when a process terminates.

### 3. I/O Management
I/O operations are simulated by transitioning processes to the **WAITING** state when performing I/O tasks. After the operation is complete, the process transitions back to the **READY** state.

## Project Structure
```
├── main.c                  # Main program that runs the simulation
├── README.md               # This file
├── Makefile                # (Optional) For building the project
└── LICENSE                 # Project license (if applicable)
```

## Features
- **Process States**: READY, WAITING, TERMINATED
- **Round-Robin Scheduling**: Simulates process execution in time slices.
- **Memory Allocation**: Simulates memory allocation and deallocation with the First-Fit algorithm.
- **I/O Simulation**: Simulates I/O operations by pausing processes.

## How to Run

### Prerequisites
You need a **C compiler** such as **GCC** or **Clang** to compile and run the project.

#### For GCC:
1. **Install GCC** if not already installed.
   - On Linux: `sudo apt-get install gcc`
   - On macOS: `brew install gcc`
   - On Windows: Use **MinGW** or install **Cygwin**.
   
#### For Clang:
1. **Install Clang** if not already installed.
   - On Linux: `sudo apt-get install clang`
   - On macOS: `brew install clang`

### Steps to Run

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/01vishalyadav/os-simulation.git
   cd os-simulation
   ```

2. Compile the `main.c` file using GCC or Clang:

   **Using GCC:**
   ```bash
   gcc -o os_simulation main.c
   ```

   **Using Clang:**
   ```bash
   clang -o os_simulation main.c
   ```

3. Run the program:
   ```bash
   ./os_simulation
   ```

4. The program will simulate process scheduling, memory allocation, and I/O operations, and display the results in the terminal.

## Example Output

### Memory Blocks (Initial):
```
Memory Blocks:
00000000000000000000...
```

### Process Table (During Execution):
```
ID      State           Burst Time      Priority    Memory
--------------------------------------------------------------
1       READY           10              1           20KB
2       READY           15              2           30KB
3       READY           8               3           40KB
```

### After Running (Processes Terminated):
```
Process 1 terminated.
Memory released for process 1.
Process 2 terminated.
Memory released for process 2.
```

## Code Explanation

### Step 1: Defining Structures
The project uses a `Process` structure to represent each process in the system. Each process has:
- **ID**: Unique identifier for each process.
- **State**: Current state of the process (READY, WAITING, TERMINATED).
- **Burst Time**: Time the process needs to execute.
- **Priority**: Priority of the process.
- **Memory**: The amount of memory allocated for the process.

### Step 2: Implementing Round-Robin Scheduling
The Round-Robin algorithm is implemented by allocating a fixed **quantum** (time slice) for each process to execute. If the process doesn't finish execution within its quantum, it is moved back to the **READY** queue.

### Step 3: Implementing First-Fit Memory Allocation
The memory allocation technique used is **First-Fit**, where each process is assigned the first available memory block that can accommodate its size. Memory is released when a process terminates.

### Step 4: Simulating I/O Management
When a process needs to perform an I/O operation, it is moved to the **WAITING** state. Once the I/O operation is complete, it is moved back to the **READY** state to continue execution.

### Step 5: Displaying Process Table
The project displays a table showing the state of each process during execution. The table includes:
- **ID**: Process ID.
- **State**: Current state (READY, WAITING, TERMINATED).
- **Burst Time**: Remaining burst time for execution.
- **Priority**: Priority of the process.
- **Memory**: Memory allocated to the process.

The output of the program simulates process execution and memory allocation in a simplified manner.

## Contribution

Feel free to fork the repository, make improvements, and create pull requests. Contributions are always welcome!

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
If you have any questions or need further assistance, feel free to reach out to me via my **Topmate** page: https://topmate.io/vishalyadav01
