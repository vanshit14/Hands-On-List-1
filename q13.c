#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int ret;

    // select() to monitor STDIN (file descriptor 0)
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Set the maximum waiting time to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    // Wait until STDIN becomes ready for reading
    // or until the 10-second timeout expires.
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1)
    {
        printf("select() failed\n");
        return 1;
    }
    else if (ret == 0)
    {
        // select() returned 0 means the timeout expired
        // and no input was available.
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else
    {
        // select() returned a positive value means
        // at least one monitored file descriptor is ready.
        if (FD_ISSET(STDIN_FILENO, &readfds))
        {
            printf("Data is available on STDIN within 10 seconds.\n");

            // Read and display the input
            char buffer[100];
            int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

            if (n > 0)
            {
                buffer[n] = '\0';
                printf("You entered: %s", buffer);
            }
        }
    }

    return 0;
}


// Waiting for input for 10 seconds...
// No data available on STDIN within 10 seconds.
// vanshit@Vanshit:~/college$ ./a.out
// Waiting for input for 10 seconds...
// hello, my name is Vanshit
// Data is available on STDIN within 10 seconds.
// You entered: hello, my name is Vanshit