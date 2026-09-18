#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct flock lock;

    // Open the file for reading.
    fd = open("file1", O_RDONLY);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // F_RDLCK means we want a READ lock.
    lock.l_type = F_RDLCK;

    // Start from the beginning of the file.
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;

    // Lock the entire file.
    lock.l_len = 0;

    // Acquire the read lock.
    // If a conflicting write lock exists,
    // wait until it is released.
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        printf("Error acquiring read lock\n");
        close(fd);
        return 1;
    }

    printf("Read lock acquired.\n");
    printf("File is locked for reading. Press Enter to release the lock...\n");

    getchar();

    // Release the lock.
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        printf("Error releasing lock\n");
    }
    else
    {
        printf("Read lock released.\n");
    }

    close(fd);

    return 0;
}

//output
// Read lock acquired.
// File is locked for reading. Press Enter to release the lock...

// Read lock released.