#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, fd3, fd4, fd5;

    // Create/open five new files
    fd1 = open("file1.txt", O_CREAT | O_RDWR, 0644);
    fd2 = open("file2.txt", O_CREAT | O_RDWR, 0644);
    fd3 = open("file3.txt", O_CREAT | O_RDWR, 0644);
    fd4 = open("file4.txt", O_CREAT | O_RDWR, 0644);
    fd5 = open("file5.txt", O_CREAT | O_RDWR, 0644);

    // Print the file descriptor values
    printf("FD of file1.txt = %d\n", fd1);
    printf("FD of file2.txt = %d\n", fd2);
    printf("FD of file3.txt = %d\n", fd3);
    printf("FD of file4.txt = %d\n", fd4);
    printf("FD of file5.txt = %d\n", fd5);

    // Infinite loop
    // Keeps the process alive so that we can inspect /proc/PID/fd
    while (1)
    {
        sleep(1);
    }

    return 0;
}

// vanshit@Vanshit:~/college$ ./a.out &
// [1] 1642
// FD of file1.txt = 3
// FD of file2.txt = 4
// FD of file3.txt = 5
// FD of file4.txt = 6
// FD of file5.txt = 7
// ls -l /proc/1642/fd
// total 0
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 0 -> /dev/pts/0
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 1 -> /dev/pts/0
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 2 -> /dev/pts/0
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 3 -> /home/vanshit/college/file1.txt
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 4 -> /home/vanshit/college/file2.txt
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 5 -> /home/vanshit/college/file3.txt
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 6 -> /home/vanshit/college/file4.txt
// lrwx------ 1 vanshit vanshit 64 Sep 15 05:12 7 -> /home/vanshit/college/file5.txt