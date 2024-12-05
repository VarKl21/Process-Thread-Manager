#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <thread>
#include <vector>
#include "resource_manager.h"
#include "thread_pool.h"
#include "ipc_manager.h"
#include "deadlock_detection.h"
#include "thread_sync.h"

// Global variables to hold user inputs
int num_threads;
int num_processes;

// Function to create processes
void create_processes(int num) {
	std::cout << "Creating " << num << " processes..." << std::endl;
	for (int i = 1; i <= num; ++i) {
    	pid_t pid = fork();
   	 
    	if (pid == -1) {
        	std::cerr << "Error creating process " << i << std::endl;
    	} else if (pid == 0) {
        	// In child process
        	std::cout << "Process " << i << " created. Process ID: " << getpid() << std::endl;
       	 
        	// Example: Child process can run a task (e.g., listing files)
        	execlp("ls", "ls", NULL);  // This will list files in the current directory
       	 
        	// Exit the child process after executing the task
        	exit(0);
    	} else {
        	// In parent process
        	std::cout << "Parent waiting for process " << i << " to finish..." << std::endl;
        	waitpid(pid, NULL, 0);  // Wait for child process to terminate
    	}
	}
	std::cout << "Processes completed and terminated." << std::endl;
}

// Function to manage thread pool
void manage_thread_pool(int num) {
	std::cout << "Creating " << num << " threads using ThreadPool..." << std::endl;
	ThreadPool pool(num);  // Use the ThreadPool class to manage threads

	std::cout << "Threads are performing their tasks concurrently." << std::endl;
}

// Function to show the menu
void show_menu() {
	std::cout << "\n1. Create processes\n";
	std::cout << "2. Manage thread pool\n";
	std::cout << "3. Detect deadlock\n";
	std::cout << "4. Perform thread synchronization\n";
	std::cout << "5. Inter-Process Communication (IPC)\n";
	std::cout << "6. Resource Allocation Tracking\n";
	std::cout << "7. Priority Inheritance Protocol\n";
	std::cout << "Enter your choice: ";
}

int main() {
	// User input
	std::cout << "Process Manager Simulation" << std::endl;
	std::cout << "Enter the number of threads you want to create: ";
	std::cin >> num_threads;

	std::cout << "Enter the number of processes you want to create: ";
	std::cin >> num_processes;

	int choice;
	bool running = true;

	while (running) {
    	show_menu();
    	std::cin >> choice;

    	switch (choice) {
        	case 1:
            	create_processes(num_processes);
            	break;
        	case 2:
            	manage_thread_pool(num_threads);  // Managing thread pool with actual threads
            	break;
        	case 3:
            	std::cout << "Deadlock detection initiated..." << std::endl;
            	detect_deadlock();
            	break;
        	case 4:
            	std::cout << "Thread synchronization initiated..." << std::endl;
            	sync_threads();
            	break;
        	case 5:
            	std::cout << "Inter-Process Communication initiated..." << std::endl;
            	ipc_demo();
            	break;
        	case 6:
            	std::cout << "Resource Allocation Tracking initiated..." << std::endl;
            	track_resources_demo();
            	break;
        	case 7:
            	std::cout << "Priority Inheritance Protocol initiated..." << std::endl;
            	priority_inheritance_demo();
            	break;
        	default:
            	std::cout << "Invalid choice, please try again." << std::endl;
    	}

    	std::cout << "\nDo you want to perform another operation? (y/n): ";
    	char again;
    	std::cin >> again;

    	if (again == 'n' || again == 'N') {
        	running = false;
    	}
	}

	std::cout << "Exiting program..." << std::endl;
	return 0;
}
