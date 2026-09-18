#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd2;

    // Open file in read-write mode
    // O_APPEND means every write happens at the end of the file
    fd = open("file1", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Duplicate the file descriptor
    fd2 = dup(fd);

    if (fd2 == -1)
    {
        printf("dup failed\n");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicate FD = %d\n", fd2);

    // Write using original file descriptor
    write(fd, "Hello", 5);

    // Write using duplicate file descriptor
    write(fd2, "World", 5);

    // Close both descriptors
    close(fd);
    close(fd2);

    return 0;
}


//output
// Original FD = 3
// Duplicate FD = 4
// vanshit@Vanshit:~/college$ cat file1
// Hello World
// HelloWorld -> Hello by fd1, World by fd2