#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent process started\n");

    pid_t child_pid2 = fork();

    if (child_pid2 < 0)
    {
        fprintf(stderr, "Fork for Process 2 failed\n");
        return 1;
    }
    else if (child_pid2 == 0)
    {
        printf("Process 2 started\n");
        sleep(2);
        printf("Process 2 finished\n");
        exit(0);
    }
    else
    {
        pid_t child_pid3 = fork();

        if (child_pid3 < 0) {
            fprintf(stderr, "Fork for Process 3 failed\n");
            return 1;
        }
        else if (child_pid3 == 0)
        {
            printf("Process 3 started\n");
            sleep(3);
            printf("Process 3 finished\n");
            exit(0);
        }
        else
        {
            int status2, status3;
            wait(&status2);
            wait(&status3);
            printf("Parent process finished\n");
        }
    }

    return 0;
}
