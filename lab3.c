//11 Topics
// CPU Scheduling Algorithms
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

//2 id cards --> name, id gpa 
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
//     int completed = 0, currentTime = 0;
//     while (completed < n) {
//         int idx = -1, minBT = 1e9;
//         for (int i = 0; i < n; i++) {
//             if (proc[i].at <= currentTime && proc[i].remainingTime > 0) {
//                 if (proc[i].remainingTime < minBT) {
//                     minBT = proc[i].remainingTime;
//                     idx = i;
//                 }
//             }
//         }
//         if (idx != -1) {
//             proc[idx].remainingTime--;
//             if (proc[idx].remainingTime == 0) {
//                 proc[idx].ct = currentTime + 1;
//                 proc[idx].tat = proc[idx].ct - proc[idx].at;
//                 proc[idx].wt = proc[idx].tat - proc[idx].bt;
//                 completed++;
//             }
//         }
//         currentTime++;
//     }
// }
