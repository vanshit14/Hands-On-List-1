#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check if a name was provided
    if (argc < 2)
    {
        printf("Please provide a name.\n");
        return 1;
    }

    printf("Hello, %s\n", argv[1]);

    return 0;
}

// vanshit@Vanshit:~/college$ gcc q25_b1.c -o greet
// vanshit@Vanshit:~/college$ gcc q25_b2.c
// vanshit@Vanshit:~/college$ ./a.out Vanshit
// Hello, Vanshit