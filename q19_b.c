#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process started.\n");
    printf("Process ID: %d\n", getpid());

    while (1)
    {
        printf("Process is going to sleep.\n");

        // Process sleeps for 10 seconds
        sleep(20);

        printf("Process woke up.\n");
    }

    return 0;
}

// ./process_states
// Process started.
// Process ID: 1478
// Process is going to sleep.

// ps -o pid,stat,cmd -p 1478
//     PID STAT CMD
//    1478 S+   ./process_states

//kill -STOP 1478
// vanshit@Vanshit:~/college$ ps -o pid,stat,cmd -p 1478
//     PID STAT CMD
//    1478 T    ./process_states