#include <stdio.h>
#include <unistd.h>

int main()
{
    // Create a symbolic (soft) link
    // "file1.txt"     -> original file
    // "softlink.txt"  -> name of the soft link
    symlink("file.txt", "softlink.txt");

    printf("Soft link created successfully.\n");

    return 0;
}

//output
// -rwxr-xr-x 1 vanshit vanshit 15992 Sep 15 04:50 a.out
// -rw-r--r-- 1 vanshit vanshit     6 Sep 15 04:39 file.txt
// -rw-r--r-- 2 vanshit vanshit     3 Sep 15 04:46 file1.txt
// -rw-r--r-- 2 vanshit vanshit     3 Sep 15 04:46 hardlink.txt
// prw-r--r-- 1 vanshit vanshit     0 Sep 15 04:50 myfifo
// -rw-r--r-- 1 vanshit vanshit   285 Sep 15 04:41 q1_a.c
// -rw-r--r-- 1 vanshit vanshit   276 Sep 15 04:45 q1_b.c
// -rw-r--r-- 1 vanshit vanshit   284 Sep 15 04:50 q1_c.c
// lrwxrwxrwx 1 vanshit vanshit     8 Sep 15 04:42 softlink.txt -> file.txt