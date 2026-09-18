#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // Open an existing file in read-write mode
    int fd = open("test.txt", O_RDWR);

    // Check whether the file was opened successfully
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Print the file descriptor
    printf("File opened successfully\n");
    printf("File descriptor = %d\n", fd);

    // Close the file
    close(fd);

    return 0;
}