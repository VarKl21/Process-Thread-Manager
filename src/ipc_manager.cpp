#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <sys/wait.h>

void create_process_with_pipe() {
    int pipe_fd[2];
    pipe(pipe_fd);  // Create a pipe

    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        exit(1);
    }

    if (pid == 0) {  // Child process
        const char* msg = "Hello from child!";
        write(pipe_fd[1], msg, strlen(msg) + 1);  // Send message to parent
        close(pipe_fd[1]);
        exit(0);
    } else {  // Parent process
        char buffer[100];
        read(pipe_fd[0], buffer, sizeof(buffer));  // Receive message from child
        std::cout << "Parent received: " << buffer << std::endl;
        close(pipe_fd[0]);
        wait(NULL);  // Wait for child to finish
    }
}



