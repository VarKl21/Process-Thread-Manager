#include "../include/thread_sync.h"
#include <iostream>
#include <pthread.h>
#include <queue>
#include <vector>

struct Thread {
	int id;
	int priority;
};

struct ComparePriority {
	bool operator()(Thread const& t1, Thread const& t2) {
    	return t1.priority < t2.priority;  // Higher priority first
	}
};

pthread_mutex_t shared_resource = PTHREAD_MUTEX_INITIALIZER;

void sync_threads() {
	std::cout << "Synchronizing threads..." << std::endl;
	// You can add thread synchronization logic here, for example:
	pthread_mutex_lock(&shared_resource);
	std::cout << "Thread synchronized" << std::endl;
	pthread_mutex_unlock(&shared_resource);
}

void priority_inheritance_demo() {
	std::priority_queue<Thread, std::vector<Thread>, ComparePriority> thread_queue;

	thread_queue.push({1, 10});  // Thread 1 with priority 10
	thread_queue.push({2, 20});  // Thread 2 with priority 20

	while (!thread_queue.empty()) {
    	Thread t = thread_queue.top();
    	thread_queue.pop();

    	pthread_mutex_lock(&shared_resource);
    	std::cout << "Thread " << t.id << " (Priority " << t.priority << ") is executing.\n";
    	pthread_mutex_unlock(&shared_resource);
	}
}




