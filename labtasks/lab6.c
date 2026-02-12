
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Global Constraints
#define MAX_P 100 // Updated to support larger test cases
#define MAX_R 50  // Updated to support larger test cases

// Parameters provided to your function:
// n, r                : Number of processes and resources
// alloc[MAX_P][MAX_R] : Allocation Matrix
// max[MAX_P][MAX_R]   : Maximum Requirement Matrix
// total[MAX_R]        : TOTAL System Resources (Sum of Allocated + Free)
// ans[MAX_P]          : Store your safe sequence here (e.g., ans[0]=1 forP1)
// *isSafe             : Set this to 1 if Safe, 0 if Unsafe

void solveBankers(int n, int r, int alloc[MAX_P][MAX_R], int max[MAX_P][MAX_R],
                  int total[MAX_R], int ans[MAX_P], int *isSafe) {
  int avalible[MAX_R];
  for (int j = 0; j < r; j++) {
    avalible[j] = total[j];
    for (int i = 0; i < n; i++) {
      avalible[j] -= alloc[i][j];
    }
  }
  // need matrix
  int need[MAX_P][MAX_R];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  // set finished
  bool finished[MAX_P];
  for (int i = 0; i < n; i++) {
    finished[i] = false;
  }

  int safeSequenceIndex = 0;
  int completed = 0;

  while (completed < n) {
    bool processfound = false;
    for (int i = 0; i < n; i++) {
      if (!finished[i]) {
        continue;
      }
      // check the process need can be satified with avalible resources
      bool canexecute = true;
      for (int j = 0; j < r; j++) {
        if (need[i][j] > avalible[j]) {
          canexecute = false;
          break;
        }
      }
      if (canexecute) {
        // execute the process
        finished[i] = true;
        completed++;
        processfound = true;
        ans[safeSequenceIndex++] = i;
        // release the resources
        for (int j = 0; j < r; j++) {
          avalible[j] += alloc[i][j];
        }
      }
    }
    if (!processfound) {
      *isSafe = 0;
      return;
    }
  }
  *isSafe = 1;
}