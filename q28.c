#include <stdio.h>
#include <unistd.h>

int main()
{
    // Print the process ID
    printf("Process ID: %d\n", getpid());

    // Keep the process running
    while (1)
    {
        sleep(1);
    }

    return 0;
}


// ps -o pid,ni,cmd -p 2715
//     PID  NI CMD
//    2715   0 ./a.out
// vanshit@Vanshit:~/college$ renice 5 -p 2715
// 2715 (process ID) old priority 0, new priority 5
// vanshit@Vanshit:~/college$