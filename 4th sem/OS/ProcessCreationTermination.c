#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    printf("Parent process (PID: %d)\n", getpid());

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Failed to create child process\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process waiting for child to terminate...\n");
        waitpid(child_pid, &status, 0);
        printf("Child process terminated\n");
    }

    printf("Parent process exiting...\n");

    return 0;
}


