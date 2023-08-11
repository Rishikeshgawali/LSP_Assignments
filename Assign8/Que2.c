#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Process 1 started\n");

    pid_t child_pid1 = fork();
    if (child_pid1 < 0)
    {
        fprintf(stderr, "Fork for Process 2 failed\n");
        return 1;
    }
    else if (child_pid1 == 0)
    {
        printf("Process 2 started (child of Process 1)\n");

        pid_t child_pid2 = fork();

        if (child_pid2 < 0)
        {
            fprintf(stderr, "Fork for Process 3 failed\n");
            return 1;
        }
        else if (child_pid2 == 0)
        {
            printf("Process 3 started (child of Process 2)\n");
            sleep(2);
            printf("Process 3 finished (child of Process 2)\n");
            exit(0);
        }
        else
        {
            int status2;
            wait(&status2);
            printf("Process 2 finished (child of Process 1)\n");
            exit(0);
        }
    }
    else
    {
        int status1;
        wait(&status1);
        printf("Process 1 finished\n");
    }

    return 0;
}
