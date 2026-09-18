#include <stdio.h>

// environ is an array of strings containing environment variables.
// Each string looks like:
// NAME=value
extern char **environ;

int main()
{
    int i = 0;

    // environ points to the first environment variable.
    // Each entry is a string, and the array ends with NULL.
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }

    return 0;
}



// SHELL=/bin/bash
// WSL2_GUI_APPS_ENABLED=1
// WSL_DISTRO_NAME=Ubuntu
// NAME=Vanshit
// PWD=/home/vanshit/college
// LOGNAME=vanshit
// HOME=/home/vanshit 
//etc