#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
    int fd;

    // Open the file before calling fork
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    // Create a child process
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0)
    {
        // Child process writes to the file
        write(fd, "Child process is writing to the file.\n", 38);
    }
    else
    {
        // Parent process writes to the file
        write(fd, "Parent process is writing to the file.\n", 39);
    }

    // Close the file
    close(fd);

    return 0;
}

//  cat output.txt
// Parent process is writing to the file.
// Child process is writing to the file.