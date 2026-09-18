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


//  gcc q25_a1.c -o hello
// vanshit@Vanshit:~/college$ gcc q25_a2.c
// vanshit@Vanshit:~/college$ ./a.out
// Executing hello program...
// Hello from the executed program.