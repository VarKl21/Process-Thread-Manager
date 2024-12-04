#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "resource_manager.h"
#include "thread_pool.h"
#include "ipc_manager.h"
#include "deadlock_detection.h"
#include "thread_sync.h"

int main() {
    // Initialize and call functions from the other modules
    create_process_with_pipe();  // From ipc_manager.cpp
    create_thread_pool();        // From thread_pool.cpp
    detect_deadlock();           // From deadlock_detection.cpp
    sync_threads();              // From thread_sync.cpp

    return 0;
}

void create_process() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        exit(1);
    }

    if (pid == 0) {  // Child process
        std::cout << "Child process is running!" << std::endl;
        exit(0);  // Child terminates
    } else {  // Parent process
        wait(NULL);  // Wait for child process to finish
        std::cout << "Parent process, child terminated!" << std::endl;
    }
}



