#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ret;

    // Open file in read-write mode.
    // Create it if it doesn't exist.
    // Truncate it if it already exists.
    fd = open("learn_lseek.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Write first 10 bytes
    write(fd, "ABCDEFGHIJ", 10);

    // Move file pointer forward by 10 bytes
    // SEEK_CUR means move relative to current position
    ret = lseek(fd, 10, SEEK_CUR);

    // Check return value of lseek()
    if (ret == -1)
    {
        printf("lseek failed\n");
        close(fd);
        return 1;
    }

    printf("Return value of lseek = %d\n", ret);

    // Write another 10 bytes
    write(fd, "KLMNOPQRST", 10);

    
    close(fd);

    return 0;
}

// vanshit@Vanshit:~/college$ ./a.out
// Return value of lseek = 20