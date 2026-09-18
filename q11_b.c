#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd2;

    // Open file in append mode
    fd = open("file1", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Duplicate fd into file descriptor 10
    fd2 = dup2(fd, 10);

    if (fd2 == -1)
    {
        printf("dup2 failed\n");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicate FD = %d\n", fd2);

    // Write using original descriptor
    write(fd, "Hello_dup2", 10);

    // Write using duplicate descriptor
    write(fd2, "World_dup2", 10);

    // Close both
    close(fd);
    close(fd2);

    return 0;
}



// Original FD = 3
// Duplicate FD = 10
// vanshit@Vanshit:~/college$ cat file1
// Hello World
// HelloWorld
// Hello_dup2World_dup2 (by dup2)