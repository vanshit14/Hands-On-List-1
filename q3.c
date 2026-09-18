#include <stdio.h>
#include <fcntl.h>

int main()
{
    // Create a file named "test.txt"
    // 0644 = read/write permissions for owner,
    //        read permission for group and others
    int fd = creat("test.txt", 0644);

    // Print the file descriptor returned by creat()
    printf("File descriptor = %d\n", fd);

    return 0;
}


// File descriptor = 3