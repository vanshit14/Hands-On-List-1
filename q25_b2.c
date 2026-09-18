#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if a name was provided
    if (argc < 2)
    {
        printf("Usage: ./a.out name\n");
        return 1;
    }

    // Execute greet and pass the name to it
    execl("./greet", "./greet", argv[1], NULL);

    // This runs only if exec fails
    perror("exec failed");

    return 1;
}

// vanshit@Vanshit:~/college$ gcc q25_b1.c -o greet
// vanshit@Vanshit:~/college$ gcc q25_b2.c
// vanshit@Vanshit:~/college$ ./a.out Vanshit
// Hello, Vanshit