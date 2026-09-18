#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        printf("Child process started.\n");
        printf("Child PID: %d\n", getpid());
        printf("Original Parent PID: %d\n", getppid());

        // Wait for the parent to terminate
        sleep(10);

        // Check the new parent after the original parent terminates
        printf("\nChild is still running.\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());

        sleep(10);
    }
    else
    {
        // Parent process
        printf("Parent process started.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        // Parent terminates before the child
        printf("Parent process is terminating.\n");
        return 0;
    }

    return 0;
}

// Parent process started.
// Parent PID: 1938
// Child PID: 1939
// Parent process is terminating.
// Child process started.
// Child PID: 1939
// Original Parent PID: 326
// Child is still running.
// Child PID: 1939
// New Parent PID: 326