
#include <iostream>
#include <thread>
#include <mutex>
#include "deadlock_detection.h"

// Mutexes used to simulate a potential deadlock
std::mutex m1, m2;

// Thread function 1
void thread1() {
    std::lock(m1, m2);  // Lock both mutexes
    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);

    std::cout << "Thread 1 acquired both locks!" << std::endl;
}

// Thread function 2
void thread2() {
    std::lock(m1, m2);  // Lock both mutexes
    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);

    std::cout << "Thread 2 acquired both locks!" << std::endl;
}

// Deadlock detection function
void detect_deadlock() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    std::cout << "Deadlock detection simulated!" << std::endl;
}



