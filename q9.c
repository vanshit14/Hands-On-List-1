#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat s;

    // Get information about the file
    if (stat("file1", &s) == -1)
    {
        printf("Error getting file information\n");
        return 1;
    }

    // a. Inode number
    printf("Inode number       : %ld\n", s.st_ino);

    // b. Number of hard links
    printf("Hard links         : %ld\n", s.st_nlink);

    // c. User ID of owner
    printf("UID                : %d\n", s.st_uid);

    // d. Group ID of owner
    printf("GID                : %d\n", s.st_gid);

    // e. File size in bytes
    printf("File size          : %ld bytes\n", s.st_size);

    // f. Block size
    printf("Block size         : %ld bytes\n", s.st_blksize);

    // g. Number of blocks allocated
    printf("Number of blocks   : %ld\n", s.st_blocks);

    // h. Time of last access
    printf("Last access        : %s", ctime(&s.st_atime));

    // i. Time of last modification
    printf("Last modification  : %s", ctime(&s.st_mtime));

    // j. Time of last change
    printf("Last change        : %s", ctime(&s.st_ctime));

    return 0;
}



// vanshit@Vanshit:~/college$ ./a.out
// Inode number       : 13244
// Hard links         : 1
// UID                : 1000
// GID                : 1000
// File size          : 12 bytes
// Block size         : 4096 bytes
// Number of blocks   : 8
// Last access        : Tue Sep 15 05:22:59 2026
// Last modification  : Tue Sep 15 05:22:26 2026
// Last change        : Tue Sep 15 05:22:26 2026