#include "../include/ipc_manager.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
 
void parent_to_child_communication() {
  int pipe_fd[2];
  if (pipe(pipe_fd) == -1) {
      std::cerr << "Pipe creation failed!" << std::endl;
      return;
  }
 
  pid_t pid = fork();
  if (pid < 0) {
      std::cerr << "Fork failed!" << std::endl;
      return;
  }
 
  if (pid == 0) {  // Child process
      close(pipe_fd[1]);  // Close write end
      char buffer[100];
      read(pipe_fd[0], buffer, sizeof(buffer));
      std::cout << "Child received: " << buffer << std::endl;
      close(pipe_fd[0]);
      _exit(0);
  } else {  // Parent process
      close(pipe_fd[0]);  // Close read end
      const char* message = "Hello from Parent!";
      write(pipe_fd[1], message, strlen(message) + 1);
      close(pipe_fd[1]);
      wait(NULL);
  }
}
void ipc_demo(){
  std::cout << "Demonstrating inter-process communication... " << std::endl;
  parent_to_child_communication();
}

