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

    // Duplicate fd using fcntl()
    // 10 means: use the lowest available FD >= 10
    fd2 = fcntl(fd, F_DUPFD, 10);

    if (fd2 == -1)
    {
        printf("fcntl failed\n");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicate FD = %d\n", fd2);

    // Write using original descriptor
    write(fd, "Hello_fcntl", 11);

    // Write using duplicate descriptor
    write(fd2, "World_fcntl", 11);


    close(fd);
    close(fd2);

    return 0;
}


// ./a.out
// Original FD = 3
// Duplicate FD = 10
// vanshit@Vanshit:~/college$ cat file1
// Hello World
// HelloWorld
// Hello_dup2World_dup2
// Hello_fcntlWorld_fcntl