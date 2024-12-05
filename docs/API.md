Process and Thread Manager API Documentation
Overview
This API enables the creation and management of processes and threads, inter-process communication, and synchronization. It also includes features like resource allocation tracking, deadlock detection, and priority inheritance.
API Reference
Base API Details
Programming Language: C
Build Tool: make
Environment: Unix/Linux
1. Process Management
Create Process
Function: create_process(char *program_path, char *args[])
Description: Creates a new process using fork() and exec().
Parameters:
program_path: Path to the executable file.
args[]: Arguments passed to the executable.
Returns:
int: PID of the created process.
Errors:
Returns -1 on failure (e.g., if fork() fails).
Terminate Process
Function: terminate_process(pid_t pid)
Description: Terminates a process using kill() and cleans up resources.
Parameters:
pid: PID of the process to terminate.
Returns:
int: 0 on success, -1 on failure.
2. Thread Pool Management
Initialize Thread Pool
Function: init_thread_pool(int size)
Description: Initializes a thread pool with a given number of threads.
Parameters:
size: Number of threads in the pool.
Returns:
int: 0 on success, -1 on failure.
Assign Task to Thread
Function: assign_task(void (*task)(void *), void *args)
Description: Assigns a task to a thread in the pool.
Parameters:
task: Function pointer to the task.
args: Arguments for the task.
Returns:
int: 0 on success, -1 if no thread is available.
3. Inter-Process Communication (IPC)
Create Pipe
Function: int create_pipe(int pipefd[2])
Description: Creates a pipe for inter-process communication.
Parameters:
pipefd[2]: Array to store file descriptors for reading and writing.
Returns:
0 on success, -1 on failure.
Write to Pipe
Function: int write_to_pipe(int fd, const void *buffer, size_t size)
Description: Writes data to a pipe.
Parameters:
fd: File descriptor of the pipe.
buffer: Data to write.
size: Size of the data.
Returns:
Number of bytes written, or -1 on failure.
4. Synchronization
Lock Resource
Function: lock_resource(pthread_mutex_t *mutex)
Description: Locks a resource using a mutex.
Parameters:
mutex: Mutex for the resource.
Returns:
0 on success, -1 on failure.
Unlock Resource
Function: unlock_resource(pthread_mutex_t *mutex)
Description: Unlocks a resource.
Parameters:
mutex: Mutex for the resource.
Returns:
0 on success, -1 on failure.
5. Deadlock Detection
Detect Deadlock
Function: int detect_deadlock()
Description: Checks for circular dependencies among processes.
Returns:
1 if deadlock is detected, 0 otherwise
