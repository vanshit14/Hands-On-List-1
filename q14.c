#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;

    // Check whether the user provided a filename
    // on the command line.
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get information about the file.
    // lstat() is used instead of stat() so that if the
    // given file is a symbolic link, we identify it as
    // a symbolic link instead of following it.
    if (lstat(argv[1], &st) == -1)
    {
        printf("Error: Cannot access file\n");
        return 1;
    }

    // Check the type of the file.
    if (S_ISREG(st.st_mode))
    {
        printf("%s is a regular file\n", argv[1]);
    }
    else if (S_ISDIR(st.st_mode))
    {
        printf("%s is a directory\n", argv[1]);
    }
    else if (S_ISFIFO(st.st_mode))
    {
        printf("%s is a FIFO (named pipe)\n", argv[1]);
    }
    else if (S_ISLNK(st.st_mode))
    {
        printf("%s is a symbolic link\n", argv[1]);
    }
    else if (S_ISCHR(st.st_mode))
    {
        printf("%s is a character device\n", argv[1]);
    }
    else if (S_ISBLK(st.st_mode))
    {
        printf("%s is a block device\n", argv[1]);
    }
    else if (S_ISSOCK(st.st_mode))
    {
        printf("%s is a socket\n", argv[1]);
    }
    else
    {
        printf("%s is an unknown file type\n", argv[1]);
    }

    return 0;
}

// ./a.out softlink.txt
// softlink.txt is a symbolic link
// ./a.out myfifo
// myfifo is a FIFO (named pipe)