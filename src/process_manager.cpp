#include "process_manager.h"
#include <iostream>
#include <unistd.h> // For fork() and exec() on Unix-based systems
#include <sys/types.h>
#include <sys/wait.h>

void create_process() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        std::cerr << "Failed to create process." << std::endl;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process created with PID: " << getpid() << std::endl;
        // Add any logic for the child process (e.g., running a command)
        execlp("/bin/echo", "echo", "Hello from the child process", (char *)NULL); // Example command
    } else {
        // Parent process
        std::cout << "Parent process with PID: " << getpid() << ", waiting for child to finish." << std::endl;
        wait(NULL); // Wait for the child to terminate
    }
}

void terminate_process() {
    // Example of terminating a process (this could be based on the process ID or other logic)
    std::cout << "Terminating the process." << std::endl;
    // Normally, you might use kill() or some other function here to terminate a process
    // Example: kill(pid, SIGTERM);  // This would require storing the PID of a child process.
}
