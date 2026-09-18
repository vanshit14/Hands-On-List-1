#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing ls -Rl using execlp:\n");

    // Execute ls by searching for it in PATH
    execlp("ls", "ls", "-Rl", NULL);

    // This runs only if execlp fails
    perror("execlp failed");

    return 1;
}