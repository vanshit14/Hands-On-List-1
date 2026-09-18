#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

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

    // Parent process exits
    if (pid > 0)
    {
        printf("Daemon process started.\n");
        printf("Parent process is terminating.\n");
        return 0;
    }

    // Create a new session
    if (setsid() == -1)
    {
        perror("setsid");
        return 1;
    }

    // Change the working directory
    chdir("/tmp");

    // Close standard input, output and error
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Wait for 10 seconds
    sleep(10);

    // Create the task file
    int fd = open("/tmp/task.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        return 1;
    }

    // Write a message into the file
    char message[] = "Task executed by daemon process.\n";

    write(fd, message, sizeof(message) - 1);

    close(fd);

    return 0;
}

// Daemon process started.
// Parent process is terminating.
// vanshit@Vanshit:~/college$ cat /tmp/task.txt
// Task executed by daemon process.