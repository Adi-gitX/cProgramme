// #  Dining Philosopher Problem — Complete Short Notes
// ---
// ## 1. What is Dining Philosopher Problem?

// The **Dining Philosopher Problem** is a classic **process synchronization** problem used to explain:

// * Deadlock
// * Starvation
// * Mutual exclusion
// * Resource sharing

// It represents **multiple processes competing for multiple shared resources**.

// ---

// ## 2. Problem Setup (Story)

// * There are **N philosophers** sitting around a circular table.
// * Between every two philosophers, there is **one fork**.
// * Each philosopher alternates between:

// 1. Thinking
// 2. Hungry
// 3. Eating

// To eat, a philosopher needs:

// > Two forks: left fork + right fork

// ---

// ## 3. Entities in the Problem

// | Entity      | Represents       |
// | ----------- | ---------------- |
// | Philosopher | Process / Thread |
// | Forks       | Shared Resources |
// | Food/Bowl   | Critical Section |

// Philosophers do **not** compete for food directly.

// They compete for **forks** to access food.

// ---

// ## 4. Philosopher States

// Each philosopher can be in one of three states:

// 1. **Thinking** → Not requesting resources
// 2. **Hungry** → Wants forks, waiting
// 3. **Eating** → Has both forks, using resources

// ---

// ## 5. Key Issues / Challenges

// ### ✅ Mutual Exclusion

// A fork can be used by **only one philosopher at a time**.

// ---

// ### ❌ Deadlock

// If all philosophers pick up their left fork together, then:

// * Everyone holds one fork
// * Everyone waits for the other fork
// * No one can eat

// System freezes.

// ---

// ### ❌ Starvation

// A philosopher may wait forever if others keep eating repeatedly.

// ---

// ### ❌ Low Concurrency

// Bad solutions allow only one philosopher to eat even when multiple could eat safely.

// ---

// ## 6. Important Observation

// ### Adjacent philosophers cannot eat simultaneously

// Because they share a fork.

// Example:

// * Philosopher 0 and 1 ❌ cannot eat together
// * Philosopher 0 and 2 ✅ can eat together

// Maximum philosophers eating at once:

// > ⌊N/2⌋

// ---

// # ✅ Solutions to Dining Philosopher Problem

// ---

// ## Solution 1: Asymmetric Fork Picking (Break Circular Wait)

// ### Idea:

// One philosopher picks forks in reverse order.

// Example:

// * All pick left then right
// * Last philosopher picks right then left

// ### Benefit:

// Breaks circular wait → avoids deadlock.

// ---

// ## Solution 2: Allow Only N−1 Philosophers to Compete

// ### Idea:

// Use a semaphore `room = N-1`

// Only `N−1` philosophers are allowed to try eating at the same time.

// ### Benefit:

// At least one philosopher always gets both forks → deadlock avoided.

// ---

// ## Solution 3: Single Mutex Lock (One-at-a-time)

// ### Idea:

// Use one global mutex:

// * Only one philosopher can pick forks and eat at a time.

// ### Benefit:

// Deadlock-free, simple.

// ### Drawback:

// Very inefficient (low parallelism).

// ---

// ## Solution 4: Tanenbaum’s Monitor / State-Based Solution (Best)

// ### Idea:

// Instead of locking forks directly, track philosopher states.

// A philosopher eats only if:

// * He is hungry
// * Left neighbor is not eating
// * Right neighbor is not eating

// ### Condition:

// ```
// if state[i] == HUNGRY
// and state[left(i)] != EATING
// and state[right(i)] != EATING
// → allow philosopher i to eat
// ```

// ### Benefit:

// * Deadlock-free
// * Starvation-free
// * Maximum concurrency

// Best practical solution.
// ---
// # ⭐ Final One-Line Summary
// Dining Philosopher Problem models how multiple processes safely share multiple resources without deadlock or starvation.
// ---

// Question

// Implement Tanenbaum's Solution
// Easy
// 2x
// xp icon
// 0/20
// Time Limit: 2, Memory Limit: 128000
// Implement Tanenbaum's Solution to the Dining Philosophers Problem using semaphores with dynamic philosopher count. The problem involves N philosophers (where N is user input) sitting at a round table where each philosopher alternates between thinking and eating. To eat, a philosopher needs two forks (chopsticks) - one from their left and one from their right. Tanenbaum's solution ensures mutual exclusion, prevents deadlock, and avoids starvation.

// In concurrent programming, multiple processes (philosophers) compete for shared resources (forks). Tanenbaum's algorithm provides a semaphore-based solution where each philosopher can eat only when both neighboring philosophers are not eating, preventing deadlock and ensuring fairness.

// Your Task: Implement the dining philosophers simulation where:

// N philosophers are created as separate threads (N is user input, 2 ≤ N ≤ 100)
// Each philosopher eats exactly 1 meal
// Synchronization is achieved using:
// A mutex semaphore to protect the shared state array
// One semaphore per philosopher for blocking/signaling
// State transitions: THINKING → HUNGRY → EATING → THINKING
// Entry Section: Uses pickup_forks() to acquire both forks atomically
// Critical Section: Philosopher eats (increments meal counter)
// Exit Section: Uses putdown_forks() to release forks and notify neighbors
// Remainder Section: Philosopher thinks
// Note 1: The Pass/Fail criteria verify that each philosopher ate exactly 1 meal, confirming mutual exclusion and absence of deadlock/starvation.

// Note 2: This is a functional problem. This is a functional problem. You do not need to take any input or print anything. Just implement the required functions following Tanenbaum's algorithm.
// // Checks if the philosopher is hungry and both neighbors are not eating, then allows eating
// void test(int philosopher_id) {
// }
// // Acquires the mutex, sets state to HUNGRY, checks availability, and blocks if forks aren't free
// void pickup_forks(int philosopher_id) {  
// }
// // Releases forks, sets state to THINKING, and checks if neighbors can now eat
// void putdown_forks(int philosopher_id) {
// }
// // Simulates the eating activity (increments meal count and sleeps for a fixed duration)
// void eat(int philosopher_id) {
// }
// // Simulates the thinking activity (sleeps for a fixed duration)
// void think(int philosopher_id) {
// }
// // Main thread function that cycles through thinking, picking up forks, eating, and putting down forks
// void* philosopher(void* arg) {
// }
// Input
// N
// where N = number of philosophers (2 ≤ N ≤ 100)
// Output
// === Final Results ===
// Philosopher 0: 1 meal(s)
// Philosopher 1: 1 meal(s)
// ...
// Philosopher (N-1): 1 meal(s)
// Total meals eaten: N

// === All philosophers have eaten ===
// No Deadlock: All philosophers completed their meal
// No Starvation: Each philosopher ate exactly 1 time

// === Test Results ===
// Result: PASS
// Constraints
// Number of philosophers: 2 ≤ N ≤ 100 (user input)
// Number of meals per philosopher: 1 (fixed)
// States: THINKING (0), HUNGRY (1), EATING (2)
// Semaphore variables:
//  - sem_t mutex: Protects critical section (initialized to 1)
//  - sem_t s[N]: One semaphore per philosopher (initialized to 0)
//  - int state[N]: Tracks each philosopher's state
//  - int philosopher_meals[N]: Tracks meals eaten by each philosopher
// Neighbour definitions:
//  - LEFT(id) = (id + N - 1) % N
//  - RIGHT(id) = (id + 1) % N
// Example
// INPUT
// 5

// OUTPUT
// === Final Results ===
// Philosopher 0: 1 meal(s)
// Philosopher 1: 1 meal(s)
// Philosopher 2: 1 meal(s)
// Philosopher 3: 1 meal(s)
// Philosopher 4: 1 meal(s)
// Total meals eaten: 5

// === All philosophers have eaten ===
// No Deadlock: All philosophers completed their meal
// No Starvation: Each philosopher ate exactly 1 time

// === Test Results ===
// Result: PASS




/*
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <assert.h>  // constraint validation

// Define a maximum limit for arrays to allow dynamic input
#define MAX_PHILOSOPHERS 100
#define MIN_PHILOSOPHERS 2
#define THINKING 0
#define HUNGRY 1
#define EATING 2

// Global variable to store the actual number of philosophers (User Input)
int num_philosophers;

// Helper Macros (using the global variable 'num_philosophers')
#define LEFT(id) (((id) + num_philosophers - 1) % num_philosophers)
#define RIGHT(id) (((id) + 1) % num_philosophers)

// Arrays sized by MAX_PHILOSOPHERS to ensure we have enough space
int state[MAX_PHILOSOPHERS];
sem_t mutex;
sem_t s[MAX_PHILOSOPHERS];
int philosopher_meals[MAX_PHILOSOPHERS] = {0};  */

// Checks if the philosopher is hungry and both neighbors are not eating, then allows eating
void test(int philosopher_id) {
    if (state[philosopher_id] == HUNGRY &&
        state[LEFT(philosopher_id)] != EATING &&
        state[RIGHT(philosopher_id)] != EATING) {
        state[philosopher_id] = EATING;  // Philosopher can eat
        sem_post(&s[philosopher_id]);  // Signal philosopher to eat
    }   
   
}

// Acquires the mutex, sets state to HUNGRY, checks availability, and blocks if forks aren't free
void pickup_forks(int philosopher_id) {
    sem_wait(&mutex);  // Enter critical section
    state[philosopher_id] = HUNGRY;  // Philosopher is now hungry
    test(philosopher_id);  // Check if philosopher can eat
    sem_post(&mutex);  // Exit critical section
   
}

// Releases forks, sets state to THINKING, and checks if neighbors can now eat
void putdown_forks(int philosopher_id) {
    sem_wait(&mutex);  // Enter critical section
    state[philosopher_id] = THINKING;  // Philosopher is now hungry
    test(LEFT(philosopher_id));  // Check if left neighbor can eat
    test(RIGHT(philosopher_id));  // Check if right neighbor can eat
    sem_post(&mutex);  // Exit critical section
   
}

// Simulates the eating activity (increments meal count and sleeps for a fixed duration)
void eat(int philosopher_id) {
    philosopher_meals[philosopher_id]++;  // Increment meal count
    usleep(500);  // Simulate eating time (500 microseconds)

   
}

// Simulates the thinking activity (sleeps for a fixed duration)
void think(int philosopher_id) {
    usleep(500); 
  
}

// Main thread function that cycles through thinking, picking up forks, eating, and putting down forks
void* philosopher(void* arg) {
    int philosopher_id = *((int*)arg);
    think (philosopher_id);
    pickup_forks(philosopher_id);
    eat(philosopher_id);
    putdown_forks(philosopher_id);
    return NULL;
    
   
}

