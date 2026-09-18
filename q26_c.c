#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char *env[] = {
        "MY_VARIABLE=Hello",
        NULL
    };

    printf("Executing ls -Rl using execle:\n");

    // Execute ls and provide a custom environment
    execle("/bin/ls", "ls", "-Rl", NULL, env);

    // This runs only if execle fails
    perror("execle failed");

    return 1;
}