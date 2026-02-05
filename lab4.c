//tasks 
// Round Robin (RR)
// Time Quantum Handling
// Ready Queue Management
// Priority Scheduling
// Priority Queue Management
// Aging Mechanism
// Performance Metrics Calculation
// Turnaround Time
// Waiting Time
// Response Time
// Comparative Analysis

//-----notes on additional CPU scheduling algorithms------->>
// Round Robin (RR) : preemptive, each process is assigned a fixed time quantum, processes are cycled through the ready queue
// Priority Scheduling : can be preemptive or non-preemptive, processes are scheduled based on priority levels
// Aging Mechanism : technique to prevent starvation by gradually increasing the priority of waiting processes
// Performance Metrics Calculation : calculating turnaround time, waiting time, and response time for processes
// Turnaround Time (TAT) : total time taken by a process from arrival to completion (TAT = CT - AT)
// Waiting Time (WT) : total time a process spends in the ready queue (WT = TAT - BT)
// Response Time (RT) : time from arrival to the first time the process gets the CPU
// Comparative Analysis : comparing different scheduling algorithms based on performance metrics like average TAT, WT, and RT

//Example-1 
// proc[i] 
// index pid at bt 
// 0     p1 0  5
// 1     p2 1  3
// 2     p3 2  1

//Ready_Queue(FIFO)
//0  1   2   3 
//p1 P2  p3  p4 
//R  F   F   R
//F

// queue implementation - front and back pointers
//circular-Queue--> when n-1th index, we are going to the 0th index
// to manage this we use modulo operation
// in insertion which pointer increases --> rear pointer 
// in deletion which pointer increases --> front pointer


//Gant-chart
// | p1 | p2 | p3 | p1 | p2 | p1 |
// 0    5    8    9   12   14   17 

//excution order
//exe_count --> always points to the next index!
//                      0    1     2    3   4   5    6
//execute order [] [] = P1   P2   P3    P1  P2  P1   

// when curr_time = 0 
// when curr time = 2 --> we need to update the curr_time, , ready queue --> update teh current pointer with next minimal arrival time process
// when all processes are added what we will do next --> we will start executing the processes in the ready queue

//BASIC REQUIREMENT TO IMPLEMENT THE ROUND ROBIN ALGORITHM
// we have to maintain Ready_queue --> we are internaly maintaining using indexes
//in_queue--> there is no process in the ready queue initially
//exe_count --> to maintain the execution order of processes
// current_time --> to maintain the current time of the CPU

void calculateTimesRR(struct Process proc[], int n, int timeQuantum, Char excutionOrder[][11], int *exe_count) {
    int currentTime = 0;
    int completed = 0;
    int remainingTime[100];
    //initialize remaining brust time 
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].bt;
    }
    // find min arrival time to start 
    int minArrival = proc[0].at;
    for (int i = 1; i < n; i++) {
        if (proc[i].at < minArrival) {
            minArrival = proc[i].at;
        }
    }
    currentTime = minArrival;
    *excutionCount = 0;
    // add all processes that have arrived at the satrt time 
    for (int i = 0; i < n; i++) {
        if (proc[i].at <= currentTime) {
            enqueue(i);
            inQueue[i] = 1;
        }
    }




    int idx = dequeue();
    while (completed < n) {
        if (idx == -1) {
            currentTime++;
            // check for newly arrived processes
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && proc[i].at <= currentTime) {
                    enqueue(i);
                    inQueue[i] = 1;
                }
            }
            idx = dequeue();
            continue;
        }

        // Execute the process for time quantum or remaining time
        if (remainingTime[idx] > timeQuantum) {
            currentTime += timeQuantum;
            remainingTime[idx] -= timeQuantum;
            // Record execution order
            strcpy(excutionOrder[(*exe_count)++], proc[idx].pid);
        } else {
            currentTime += remainingTime[idx];
            // Record execution order
            strcpy(excutionOrder[(*exe_count)++], proc[idx].pid);
            proc[idx].ct = currentTime;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            remainingTime[idx] = 0;
            completed++;
        }

        // Check for newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && proc[i].at <= currentTime) {
                enqueue(i);
                inQueue[i] = 1;
            }
        }

        // If the process is not completed, re-enqueue it
        if (remainingTime[idx] > 0) {
            enqueue(idx);
        }
    





// what we did at current time= 0 





















        // idx = dequeue();
        // inqueue[idx] = 0;
        // if (strcmp(lastexecutedPID, proc[idx].pid) != 0) {
        //     strcpy(excutionOrder[(*exe_count)++], proc[idx].pid);
        //     (*excutionCount)++;
        //     strcpy(lastexecutedPID, proc[idx].pid);
        // }
        // int executedTime = (remainingTime[idx] > timeQuantum) ? timeQuantum : remainingTime[idx];
        // currentTime += executedTime;
        // remainingTime[idx] -= executedTime;
        // // If process is completed


