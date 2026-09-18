#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;

    // Open file1 for reading
    fd1 = open("file1", O_RDONLY);

    if (fd1 == -1)
    {
        printf("Error opening file1\n");
        return 1;
    }

    // Create file2 and open it for writing
    fd2 = open("file2", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd2 == -1)
    {
        printf("Error creating file2\n");
        close(fd1);
        return 1;
    }

    // Read data from file1
    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        // Write the data into file2
        write(fd2, buffer, n);
    }

    printf("File copied successfully.\n");

    // Close both files
    close(fd1);
    close(fd2);

    return 0;
}

//output
// vanshit@Vanshit:~/college$ ./a.out
// File copied successfully.
// vanshit@Vanshit:~/college$ cat file2
// Hello World
