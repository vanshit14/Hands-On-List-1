#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {
        "ls",
        "-Rl",
        NULL
    };

    printf("Executing ls -Rl using execvp:\n");

    // Execute ls by searching for it in PATH
    execvp("ls", args);

    // This runs only if execvp fails
    perror("execvp failed");

    return 1;
}