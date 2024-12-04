
#include <iostream>
#include <pthread.h>
#include <vector>
#include "thread_pool.h"
void* worker (void* arg);
// Define the ThreadPool class first
class ThreadPool {
public:
    ThreadPool(int num_threads) {
        threads.resize(num_threads);
        for (int i = 0; i < num_threads; ++i) {
            pthread_create(&threads[i], NULL, worker, NULL);
        }
    }

    ~ThreadPool() {
        for (auto& t : threads) {
            pthread_join(t, NULL);
        }
    }

private:
    std::vector<pthread_t> threads;
};

// Define the worker function
void* worker(void* arg) {
    std::cout << "Thread is working!" << std::endl;
    return NULL;
}

// Now implement create_thread_pool
void create_thread_pool() {
    ThreadPool pool(4);  // Create a thread pool with 4 threads
    std::cout << "Thread pool created with 4 threads!" << std::endl;
}



