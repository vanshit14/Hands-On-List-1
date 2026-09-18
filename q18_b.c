#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define RECORD_SIZE 20

int main()
{
    int fd;
    int record_no;

    // Open the records file for reading
    fd = open("records.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Enter record number to read (1-3): ");
    scanf("%d", &record_no);

    // Check if the record number is valid
    if (record_no < 1 || record_no > 3)
    {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    // Calculate the starting position of the selected record
    off_t offset = (record_no - 1) * RECORD_SIZE;

    // Define the record lock
    struct flock lock;

    // Set read lock
    lock.l_type = F_RDLCK;

    // Offset is calculated from the beginning of the file
    lock.l_whence = SEEK_SET;

    // Starting position of the record
    lock.l_start = offset;

    // Lock only one record
    lock.l_len = RECORD_SIZE;

    // Store the process ID
    lock.l_pid = getpid();

    printf("\nTrying to acquire read lock on record %d...\n", record_no);

    // Wait until the record can be locked
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired on record %d.\n", record_no);

    // Move to the selected record
    lseek(fd, offset, SEEK_SET);

    // Read the record
    char record[RECORD_SIZE + 1] = {0};

    read(fd, record, RECORD_SIZE);

    printf("\nRecord %d: %s\n", record_no, record);

    // Keep the lock until the user presses Enter
    printf("\nRead lock is still active.\n");
    printf("Press ENTER to release the lock...");

    // Consume the newline left by scanf
    getchar();

    // Wait for the user to press Enter
    getchar();

    // Release the lock
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock released.\n");

    close(fd);

    return 0;
}


// Enter record number to read (1-3): 1

// Trying to acquire read lock on record 1...
// Read lock acquired on record 1.

// Record 1: vanshit_2

// Read lock is still active.
// Press ENTER to release the lock...
// Read lock released.