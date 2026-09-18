#include <stdio.h>
#include <sched.h>

int main()
{
    int min_priority;
    int max_priority;

    // Get the minimum real-time priority for SCHED_FIFO
    min_priority = sched_get_priority_min(SCHED_FIFO);

    // Get the maximum real-time priority for SCHED_FIFO
    max_priority = sched_get_priority_max(SCHED_FIFO);

    // Check if getting the priority failed
    if (min_priority == -1 || max_priority == -1)
    {
        perror("sched_get_priority");
        return 1;
    }

    printf("Minimum real-time priority: %d\n", min_priority);
    printf("Maximum real-time priority: %d\n", max_priority);

    return 0;
}


// Minimum real-time priority: 1
// Maximum real-time priority: 99