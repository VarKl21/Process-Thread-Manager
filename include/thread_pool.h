#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <pthread.h>
#include <iostream>

class ThreadPool {
public:
    ThreadPool(int num_threads);
    ~ThreadPool();

private:
    std::vector<pthread_t> threads;
    static void* worker(void* arg);
};

#endif // THREAD_POOL_H




