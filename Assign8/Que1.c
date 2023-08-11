#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Parent process started\n");

    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (child_pid == 0)
    {

        printf("Child process started\n");
        sleep(3);
        printf("Child process finished\n");
        exit(0);
    }
    else
    {

        int status;
        wait(&status);
        printf("Parent process finished\n");
    }

    return 0;
}
