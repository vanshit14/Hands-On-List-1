#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    // Create a new child process
    pid = fork();

    // Check if fork failed
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    // Code executed by the child process
    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else
    {
        // Code executed by the parent process
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        wait(NULL);
    }

    return 0;
}


//without wait null
// Parent Process
// Parent PID: 1587
// Child PID: 1588
// Child Process
// Child PID: 1588
// Parent PID: 326 //here its different as parent terminated before child

// if i add wait(null)
// Parent Process
// Parent PID: 1587
// Child PID: 1588

// Child Process
// Child PID: 1588
// Parent PID: 1587