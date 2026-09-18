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
        // Child process terminates immediately
        printf("Child process is terminating.\n");
        printf("Child PID: %d\n", getpid());

        return 0;
    }
    else
    {
        // Parent process continues running
        printf("Parent process is running.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        // Parent does not call wait()
        // So the terminated child becomes a zombie

        printf("Parent is sleeping for 30 seconds.\n");
        sleep(30);

        printf("Parent process is terminating.\n");
    }

    return 0;
}


// ps -o pid,ppid,stat,cmd -p 1854
//     PID    PPID STAT CMD
//    1854    1853 Z+   [a.out] <defunct>

//significance of wait is that parent collects childs exit status