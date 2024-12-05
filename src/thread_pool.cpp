#include <iostream>
#include <pthread.h>
#include <vector>

// Define the ThreadPool class
class ThreadPool {
public:
    // Constructor to initialize the pool with the given number of threads
    ThreadPool(int num_threads) {
        threads.resize(num_threads);  // Resize the vector to hold thread IDs
        for (int i = 0; i < num_threads; ++i) {
            pthread_create(&threads[i], NULL, worker, (void*)(intptr_t)i);  // Create each thread, passing the thread ID
        }
    }

    // Destructor to join all threads (wait for them to finish)
    ~ThreadPool() {
        for (auto& t : threads) {
            pthread_join(t, NULL);  // Wait for each thread to finish
        }
    }

private:
    std::vector<pthread_t> threads;  // Vector to hold the thread IDs

    // Worker function that each thread will execute
    static void* worker(void* arg) {
        int thread_id = (int)(intptr_t)arg;  // Cast the arg to the thread ID
        std::cout << "Thread " << thread_id << " is working!" << std::endl;

        // Example 
        int result = 0;
        for (int i = 0; i < 1000; ++i) {
            result += i; 
        }

        std::cout << "Thread " << thread_id << " finished its work. Result: " << result << std::endl;
        return NULL;
    }
};

// Function to create a thread pool
void create_thread_pool() {
    ThreadPool pool(4);  // Create a thread pool with 4 threads
    std::cout << "Thread pool created with 4 threads!" << std::endl;
}
