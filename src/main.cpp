#include <iostream>
#include "process_manager.h"

int main() {
    std::cout << "Process and Thread Manager Started" << std::endl;

    // Call the create_process function to create a new process
    create_process();

    // If you want to test terminating a process, 
    // you'd typically need to track the PID and call terminate_process with it.
    // For this example, let's simulate terminating a process
    pid_t some_pid = 12345;  // Replace with an actual PID for testing
    terminate_process(some_pid);

    return 0;
}

