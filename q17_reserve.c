#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket;
    int n;
    struct flock lock;
    char buffer[20];
    char output[20];

    // Open the file for both reading and writing.
    fd = open("ticket.txt", O_RDWR);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Set up a write lock.
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // Acquire the write lock.
    // If another process already has the lock,
    // this process waits here.
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        printf("Error acquiring lock\n");
        close(fd);
        return 1;
    }

    printf("Write lock acquired.\n");

    // Pause here so that we can easily test the lock
    // using another terminal.
    printf("Press Enter to reserve the ticket...\n");
    getchar();

    // Move to the beginning of the file.
    lseek(fd, 0, SEEK_SET);

    // Read the current ticket number as text.
    n = read(fd, buffer, sizeof(buffer) - 1);

    // Make buffer a proper C string.
    buffer[n] = '\0';

    // Convert text to integer.
    sscanf(buffer, "%d", &ticket);

    // Increment the ticket number.
    ticket++;

    // Move back to the beginning of the file.
    lseek(fd, 0, SEEK_SET);

    // Remove the old ticket number.
    ftruncate(fd, 0);

    // Convert the new ticket number to text.
    n = sprintf(output, "%d", ticket);

    // Write the new ticket number.
    write(fd, output, n);

    printf("New ticket number = %d\n", ticket);

    // Release the write lock.
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);

    return 0;
}


// Write lock acquired.
// Press Enter to reserve the ticket...

// New ticket number = 12
// Write lock released.

// Write lock acquired.
// Press Enter to reserve the ticket...

// New ticket number = 13
// Write lock released.