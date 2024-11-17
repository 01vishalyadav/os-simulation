#include <stdio.h>
#include <string.h>
#include <unistd.h> // For sleep

#define MEMORY_SIZE 100
#define TIME_SLICE 3

typedef struct {
    int id;
    char state[15];        // READY, RUNNING, WAITING, TERMINATED
    int burst_time;        // Simulated CPU time required
    int priority;          // For priority scheduling
    int memory_required;   // Memory needed in KB
    int memory_start;      // Start block of allocated memory (-1 if not allocated)
} Process;

// Display processes
void display_processes(Process processes[], int n) {
    printf("ID      State           Burst Time      Priority    Memory\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(processes[i].state, "TERMINATED") == 0) {
            printf("%-8d%-16s%-16s%-12d%dKB\n",
                   processes[i].id, processes[i].state, "-", processes[i].priority, processes[i].memory_required);
        } else {
            printf("%-8d%-16s%-16d%-12d%dKB\n",
                   processes[i].id, processes[i].state, processes[i].burst_time, processes[i].priority, processes[i].memory_required);
        }
    }
    printf("\n");
}

// Display memory
void display_memory(int memory[], int size) {
    printf("Memory Blocks:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", memory[i]);
    }
    printf("\n\n");
}

// Allocate memory using first-fit algorithm
int allocate_memory(int memory[], int size, int required) {
    for (int i = 0; i < size; i++) {
        if (memory[i] == 0) {
            int j;
            for (j = i; j < i + required && j < size; j++) {
                if (memory[j] != 0) break;
            }
            if (j == i + required) {
                for (j = i; j < i + required; j++) {
                    memory[j] = 1; // Mark as allocated
                }
                return i; // Return starting block
            }
        }
    }
    return -1; // Allocation failed
}

// Release allocated memory
void release_memory(int memory[], int size, int start, int required) {
    for (int i = start; i < start + required && i < size; i++) {
        memory[i] = 0; // Mark as free
    }
}

// Handle I/O requests
void handle_io(Process processes[], int n, int process_id) {
    for (int i = 0; i < n; i++) {
        if (processes[i].id == process_id) {
            printf("Process %d performing I/O...\n", processes[i].id);
            strcpy(processes[i].state, "WAITING");
            display_processes(processes, n);
            sleep(2); // Simulate I/O delay
            strcpy(processes[i].state, "READY");
            printf("Process %d completed I/O.\n", processes[i].id);
            break;
        }
    }
}

// Round-robin scheduling
void round_robin(Process processes[], int n, int memory[], int memory_size) {
    int all_done = 0;
    while (!all_done) {
        all_done = 1;
        for (int i = 0; i < n; i++) {
            if (strcmp(processes[i].state, "READY") == 0) {
                printf("Running process %d...\n", processes[i].id);

                // Simulate process execution
                processes[i].burst_time -= TIME_SLICE;
                if (processes[i].burst_time <= 0) {
                    processes[i].burst_time = 0;
                    strcpy(processes[i].state, "TERMINATED");
                    printf("Process %d terminated.\n", processes[i].id);

                    // Release allocated memory
                    if (processes[i].memory_start != -1) {
                        release_memory(memory, memory_size, processes[i].memory_start, processes[i].memory_required);
                        printf("Memory released for process %d.\n", processes[i].id);
                        display_memory(memory, memory_size);
                    }
                } else {
                    printf("Process %d executed for %d units.\n", processes[i].id, TIME_SLICE);
                }
                all_done = 0;
            }
        }
        display_processes(processes, n);
    }
}

int main() {
    // Initialize processes
    Process processes[] = {
        {1, "READY", 10, 1, 20, -1},
        {2, "READY", 15, 2, 30, -1},
        {3, "READY", 8, 3, 40, -1}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Initialize memory
    int memory[MEMORY_SIZE] = {0};
    display_memory(memory, MEMORY_SIZE);

    // Allocate memory for processes
    for (int i = 0; i < n; i++) {
        int block = allocate_memory(memory, MEMORY_SIZE, processes[i].memory_required);
        if (block != -1) {
            processes[i].memory_start = block;
            printf("Memory allocated for process %d at block %d.\n", processes[i].id, block);
        } else {
            printf("Memory allocation failed for process %d!\n", processes[i].id);
        }
    }
    display_memory(memory, MEMORY_SIZE);

    // Display initial processes
    display_processes(processes, n);

    // Simulate I/O for one process
    handle_io(processes, n, 2);

    // Start round-robin scheduling
    round_robin(processes, n, memory, MEMORY_SIZE);

    return 0;
}
