#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define RECORD_SIZE 20

// Create the file with three records if it does not exist
void create_file()
{
    int fd = open("records.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    // Check if the file is empty
    off_t size = lseek(fd, 0, SEEK_END);

    if (size == 0)
    {
        char records[3][RECORD_SIZE] = {
            "Alice",
            "Bob",
            "Charlie"
        };

        // Write the three records
        for (int i = 0; i < 3; i++)
        {
            char record[RECORD_SIZE] = {0};

            strcpy(record, records[i]);

            write(fd, record, RECORD_SIZE);
        }

        printf("Created records.txt with 3 records.\n");
    }

    close(fd);
}

int main()
{
    int fd;
    int record_no;
    char new_data[RECORD_SIZE];

    // Create the file if it does not exist
    create_file();

    // Open the file for reading and writing
    fd = open("records.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Enter record number to modify (1-3): ");
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

    // Set write lock
    lock.l_type = F_WRLCK;

    // Offset is calculated from the beginning of the file
    lock.l_whence = SEEK_SET;

    // Starting position of the record
    lock.l_start = offset;

    // Lock only one record
    lock.l_len = RECORD_SIZE;

    // Store the process ID
    lock.l_pid = getpid();

    printf("\nTrying to acquire write lock on record %d...\n", record_no);

    // Wait until the record can be locked
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired on record %d.\n", record_no);

    // Read the current record
    char old_data[RECORD_SIZE] = {0};

    lseek(fd, offset, SEEK_SET);
    read(fd, old_data, RECORD_SIZE);

    printf("Current record: %s\n", old_data);

    // Ask the user for the new value
    printf("Enter new value: ");
    scanf(" %[^\n]", new_data);

    // Move to the selected record
    lseek(fd, offset, SEEK_SET);

    // Create an empty record
    char record[RECORD_SIZE] = {0};

    // Copy the new value into the record
    strncpy(record, new_data, RECORD_SIZE - 1);

    // Write the modified record
    write(fd, record, RECORD_SIZE);

    printf("\nRecord %d modified successfully.\n", record_no);

    // Keep the lock until the user presses Enter
    printf("\nWrite lock is still active.\n");
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

    printf("Write lock released.\n");

    close(fd);

    return 0;
}



// Enter record number to modify (1-3): 1

// Trying to acquire write lock on record 1...
// Write lock acquired on record 1.
// Current record: Vanshit
// Enter new value: vanshit_2

// Record 1 modified successfully.

// Write lock is still active.
// Press ENTER to release the lock...
// Write lock released.