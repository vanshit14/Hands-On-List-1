#include <unistd.h>

int main()
{
    char buffer[100];
    int n;

    // Read input from STDIN
    // STDIN has file descriptor 0
    n = read(0, buffer, sizeof(buffer));

    // Write the input to STDOUT
    // STDOUT has file descriptor 1
    write(1, buffer, n);

    return 0;
}

// output
//  ./a.out
// Hello world
// Hello world