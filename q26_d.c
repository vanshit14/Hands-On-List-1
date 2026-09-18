#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {
        "ls",
        "-Rl",
        NULL
    };

    printf("Executing ls -Rl using execv:\n");

    // Execute ls using an argument array
    execv("/bin/ls", args);

    // This runs only if execv fails
    perror("execv failed");

    return 1;
}