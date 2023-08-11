#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Process 1 started\n");

    pid_t child_pid2 = fork();

    if (child_pid2 < 0)
    {
        fprintf(stderr, "Fork for Process 2 failed\n");
        return 1;
    }
    else if (child_pid2 == 0)
    {

        printf("Process 2 started (child of Process 1)\n");
        exit(0);
    }
    else
    {
        pid_t child_pid3 = fork();

        if (child_pid3 < 0)
        {
            fprintf(stderr, "Fork for Process 3 failed\n");
            return 1;
        }
        else if (child_pid3 == 0)
        {
            printf("Process 3 started (child of Process 1)\n");
            exit(0);
        }
        else
        {
            pid_t child_pid4 = fork();

            if (child_pid4 < 0)
            {
                fprintf(stderr, "Fork for Process 4 failed\n");
                return 1;
            }
            else if (child_pid4 == 0)
            {
                printf("Process 4 started (child of Process 1)\n");
                exit(0);
            }
            else
            {
                int status2, status3, status4;
                wait(&status2);
                wait(&status3);
                wait(&status4);
                printf("Process 1 finished\n");
            }
        }
    }

    return 0;
}
