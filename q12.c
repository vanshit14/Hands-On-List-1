#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;

    // Open the file in read-write mode.
    // later use fcntl() to check whether the file
    // was actually opened in read-only, write-only, or read-write mode.
    fd = open("file1", O_RDWR);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // F_GETFL asks the kernel for the file status flags
    // associated with this file descriptor.
    // These flags include the opening/access mode.
    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        printf("fcntl failed\n");
        close(fd);
        return 1;
    }

    // flags can contain many things such as O_APPEND, O_NONBLOCK, etc.
    // We only want to find the access mode:
    // O_RDONLY, O_WRONLY, or O_RDWR.
    // O_ACCMODE extracts only the access-mode part from flags.
    // O_RDONLY  0 read only
    // O_WRONLY  1  write only
    // O_RDWR    2  read and write
    if ((flags & O_ACCMODE) == O_RDONLY)
    {
        printf("File opened in READ ONLY mode\n");
    }
    else if ((flags & O_ACCMODE) == O_WRONLY)
    {
        printf("File opened in WRITE ONLY mode\n");
    }
    else if ((flags & O_ACCMODE) == O_RDWR)
    {
        printf("File opened in READ-WRITE mode\n");
    }

    // We are finished using the file, so close its file descriptor.
    close(fd);

    return 0;
}


//File opened in READ-WRITE mode