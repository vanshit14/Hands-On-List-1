#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing ls -Rl using execl:\n");

    // Execute ls using its complete path
    execl("/bin/ls", "ls", "-Rl", NULL);

    // This runs only if execl fails
    perror("execl failed");

    return 1;
}