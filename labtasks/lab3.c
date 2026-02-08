//11 Topics
// CPU Scheduling Algorithms --> like FCFS, SJF, SRTF 
// Input Handling for Processes 
// Arrival Time and Burst Time
// First-Come-First-Served (FCFS)
// Queue Management
// Completion Time Calculation
// Shortest Job First (SJF)
// SRTF (Preemptive SJF)
// Preemption Logic
// Remaining Time Tracking
// Gantt Chart Generation

//-----notes on CPU scheduling algorithms------->>
// differences between fcfs fjs and srtf
// FCFS : non preemptive, processes are executed in the order they arrive
// SJF : non preemptive, processes with the shortest burst time are executed first
// SRTF : preemptive, processes with the shortest remaining time are executed first, can interrupt running processes

// input handling for processes - reading process details like process id, arrival time, burst time from user or file

// arrival time - the time when a process arrives in the ready queue
// burst time - the total time required by a process for execution on CPU
// completion time - the time when a process completes its execution
// turn around time - the total time taken by a process from arrival to completion (TAT = CT - AT)
// waiting time - the total time a process spends in the ready queue (WT = TAT - BT)

// queue management - managing the order of processes in the ready queue based on scheduling algorithm

//preemption logic - in preemptive scheduling algorithms, a running process can be interrupted if a new process arrives with a shorter burst time or remaining time
// remaining time tracking - keeping track of the remaining execution time for each process, especially important in preemptive algorithms like SRTF
// gantt chart generation - a visual representation of the order in which processes are executed on the CPU, showing start and end times for each process!


//2 id cards --> name, id gpa (example)
// struct Student {
//     char name[50];
//     int id;
//     float gpa;
// };
// struct students [120]{
//     {"Alice", 101, 3.5},
//     {"Bob", 102, 3.7},
//     {"Charlie", 103, 3.9}
    
// }

//the goldern formulas 
//completion time = burst time + arrival time
//turn around time = completion time - arrival time
//waiting time = turn around time - burst time

//implement FCSS--> excute the processes in the order of arrival time
//exxample:Input
// 4
// p1 0 5 
// p2 1 3
// p3 2 8
// p4 3 6

// //Output
// pid at bt ct tat wt
// p1 0 5 5 5 0
// p2 1 3 8 7 4
// p3 2 8 16 14 6
// p4 3 6 22 19 13

// average tat = 11.25
// average wt = 5.75

// ----------FCSS code templete---------->>

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// #include <ctype.h>
// #include <stdlib.h>
// struct Process{
//     char pid[11];
//     int at, bt, ct, tat, wt;
// }
// void sortByArrival(struct Process proc[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (proc[j].at > proc[j + 1].at) {
//                 struct Process temp = proc[j];
//                 proc[j] = proc[j + 1];
//                 proc[j + 1] = temp;
//             }
//         }
//     }
// }

// void calculateTimes(struct Process proc[], int n) {
//     int currentTime = 0;
    
//     for (int i = 0; i < n; i++) {
//         if (currentTime < proc[i].at) {
//             currentTime = proc[i].at;
//         }
        
//         proc[i].ct = currentTime + proc[i].bt;
//         proc[i].tat = proc[i].ct - proc[i].at;
//         proc[i].wt = proc[i].tat - proc[i].bt;
        
//         currentTime = proc[i].ct;
//     }
// }


// sjf example 
//proc[i]  pid  at bt 
// 0      p1   0  7
// 1      p2   2  4
// 2      p3   4  4
// 3      p4   5  1
// 4      p5   8  5
// 5      p6   9  6

// gantt chart 
// | p1 | p2 | p4 | p3 | p5 | p6 |
// 0    7    11   12   16   21   27
// output
// pid at bt ct tat wt
// p1 0 7 7 7 0
// p2 2 4 11 9 5
// p3 4 4 16 12 8   
// p4 5 1 12 7 6
// p5 8 5 21 13 8
// p6 9 6 27 18 12

// average tat = 9.67
// average wt = 6.5

// ----------code templete for SJF----------->>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// struct Process{
//     char pid[11];
//     int at, bt, ct, tat, wt;
//     int remainingTime;
// };   
// void calculateTimesSJF(struct Process proc[], int n) {

//     int completed = 0;
//     int currentTime = 0;
//     int is_completed[100] = {0};

//     struct Process exec_order[100];

//     while (completed < n) {

//         int idx = -1;
//         int min_bt = 100000;

//         for (int i = 0; i < n; i++) {
//             if (!is_completed[i] && proc[i].at <= currentTime) {
//                 if (proc[i].bt < min_bt) {
//                     min_bt = proc[i].bt;
//                     idx = i;
//                 } else if (proc[i].bt == min_bt) {
//                     if (proc[i].at < proc[idx].at) {
//                         idx = i;
//                     }
//                 }
//             }
//         }

//         if (idx == -1) {
//             currentTime++;
//             continue;
//         }

//         proc[idx].ct = currentTime + proc[idx].bt;
//         proc[idx].tat = proc[idx].ct - proc[idx].at;
//         proc[idx].wt = proc[idx].tat - proc[idx].bt;

//         currentTime = proc[idx].ct;
//         exec_order[completed] = proc[idx];
//         is_completed[idx] = 1;
//         completed++;
//     }

//     for (int i = 0; i < n; i++) {
//         proc[i] = exec_order[i];
//     }
// }