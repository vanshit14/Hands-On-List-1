#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2, child3;
    int status;

    // Create the first child process
    child1 = fork();

    if (child1 < 0)
    {
        perror("fork");
        return 1;
    }

    if (child1 == 0)
    {
        printf("Child 1 is running.\n");
        printf("Child 1 PID: %d\n", getpid());

        sleep(2);

        printf("Child 1 is terminating.\n");
        return 1;
    }

    // Create the second child process
    child2 = fork();

    if (child2 < 0)
    {
        perror("fork");
        return 1;
    }

    if (child2 == 0)
    {
        printf("Child 2 is running.\n");
        printf("Child 2 PID: %d\n", getpid());

        sleep(5);

        printf("Child 2 is terminating.\n");
        return 2;
    }

    // Create the third child process
    child3 = fork();

    if (child3 < 0)
    {
        perror("fork");
        return 1;
    }

    if (child3 == 0)
    {
        printf("Child 3 is running.\n");
        printf("Child 3 PID: %d\n", getpid());

        sleep(3);

        printf("Child 3 is terminating.\n");
        return 3;
    }

    // Parent process
    printf("Parent process.\n");
    printf("Parent PID: %d\n", getpid());

    printf("Child 1 PID: %d\n", child1);
    printf("Child 2 PID: %d\n", child2);
    printf("Child 3 PID: %d\n", child3);
    
    // Wait specifically for Child 2
    printf("\nParent is waiting for Child 2.\n");

    waitpid(child2, &status, 0);

    printf("Child 2 has terminated.\n");

    // Wait for the remaining children
    waitpid(child1, NULL, 0);
    waitpid(child3, NULL, 0);

    printf("Parent process is terminating.\n");

    return 0;
}


// Child 1 is running.
// Child 1 PID: 1987
// Parent process.
// Parent PID: 1986
// Child 1 PID: 1987
// Child 2 PID: 1988
// Child 3 PID: 1989

// Parent is waiting for Child 2.
// Child 2 is running.
// Child 2 PID: 1988
// Child 3 is running.
// Child 3 PID: 1989
// Child 1 is terminating.
// Child 3 is terminating.
// Child 2 is terminating.
// Child 2 has terminated.
// Parent process is terminating.