#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    // Create the file and open it for writing.
    // O_TRUNC removes old contents.
    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Store the ticket number as readable text.
    write(fd, "10", 2);

    close(fd);

    return 0;
}