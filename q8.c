#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char ch;

    // Open the file in read-only mode
    fd = open("file1", O_RDONLY);

    // Check if file opened successfully
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file character by character
    while (read(fd, &ch, 1) > 0)
    {
        // Display the character
        write(1, &ch, 1);

        // If newline is encountered,
        // one complete line has been displayed
        if (ch == '\n')
        {
            // Continue reading the next line
            continue;
        }
    }

    // End of file reached, so close the file
    close(fd);

    return 0;
}

//file1 has hello world

//output
// Hello World