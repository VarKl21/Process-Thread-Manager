#include <gtest/gtest.h>
#include <unistd.h>
#include <sys/wait.h>

TEST(ProcessManagerTest, ForkTest) {
    pid_t pid = fork();
    
    ASSERT_NE(pid, -1) << "Fork failed!";

    if (pid == 0) {
        // Child process
        exit(0);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        ASSERT_EQ(WIFEXITED(status), 1);
    }
}





