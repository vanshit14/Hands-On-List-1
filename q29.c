#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    // Display the current policy
    if (policy == SCHED_OTHER)
        printf("Current policy: SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("Current policy: SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Current policy: SCHED_RR\n");

    // Set priority to 0 for SCHED_OTHER
    param.sched_priority = 0;

    // Change the policy to SCHED_OTHER
    if (sched_setscheduler(0, SCHED_OTHER, &param) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_OTHER.\n");

    // Get the policy again
    policy = sched_getscheduler(0);

    if (policy == SCHED_OTHER)
        printf("Current policy: SCHED_OTHER\n");

    return 0;
}


// Current policy: SCHED_OTHER
// Scheduling policy changed to SCHED_OTHER.
// Current policy: SCHED_OTHER