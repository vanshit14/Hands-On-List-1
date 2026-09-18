#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    // Create a FIFO (named pipe)
    // "myfifo" -> name of the FIFO
    // 0666     -> read and write permissions
    mkfifo("myfifo", 0666);

    printf("FIFO created successfully.\n");

    return 0;
}

//output prw-r--r-- 1 vanshit vanshit     0 Sep 15 04:50 myfifo