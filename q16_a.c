#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct flock lock;

    // Open the file for reading and writing.
    // O_CREAT creates the file if it does not already exist.
    fd = open("file1", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Set up the lock structure.
    // F_WRLCK means we want a WRITE lock.
    lock.l_type = F_WRLCK;

    // Lock from the beginning of the file.
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;

    // 0 means lock the entire file from l_start onwards.
    lock.l_len = 0;

    // Try to acquire the write lock.
    // F_SETLKW means:
    // If another process already has a conflicting lock,
    // wait until the lock becomes available.
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        printf("Error acquiring write lock\n");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");
    printf("File is locked. Press Enter to release the lock...\n");

    getchar();

    // Change the lock type to F_UNLCK to release the lock.
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        printf("Error releasing lock\n");
    }
    else
    {
        printf("Write lock released.\n");
    }

    close(fd);

    return 0;
}


//output
// Write lock acquired.
// File is locked. Press Enter to release the lock...

// Write lock released.