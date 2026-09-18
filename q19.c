#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process started.\n");
    printf("Process ID: %d\n", getpid());

    printf("Process is running.\n");
    printf("Use another terminal to check the process state.\n");

    while (1)
    {
        // Keep the process running continuously
    }

    return 0;
}

//  gcc q19.c -o process_states
// vanshit@Vanshit:~/college$ ./process_states
// Process started.
// Process ID: 1420
// Process is running.
// Use another terminal to check the process state.
//  ps -o pid,stat,cmd -p 1420
//     PID STAT CMD
//    1420 R+   ./process_states