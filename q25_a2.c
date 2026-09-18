#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing hello program...\n");

    // Execute the hello program
    execl("./hello", "./hello", NULL);

    // This runs only if exec fails
    perror("exec failed");

    return 1;
}