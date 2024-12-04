#include "thread_sync.h"
#include <iostream>
#include <pthread.h>

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function executed by the thread
void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);  // Lock the mutex
    std::cout << "Thread is safely accessing shared resource!" << std::endl;
    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

// Synchronize threads by creating and joining one
void sync_threads() {
    pthread_t thread;

    // Create a thread and run thread_function
    pthread_create(&thread, NULL, thread_function, NULL);

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    std::cout << "Threads synchronized!" << std::endl;
}




