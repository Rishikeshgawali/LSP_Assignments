#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent process started\n");

    pid_t child_pid1 = fork();
    if (child_pid1 < 0)
    {
        fprintf(stderr, "Fork for Child1 failed\n");
        return 1;
    }
    else if (child_pid1 == 0)
    {
        printf("Child1 process started\n");
        sleep(2);
        printf("Child1 process finished\n");
        exit(0);
    }
    else
    {
        pid_t child_pid2 = fork();

        if (child_pid2 < 0)
        {
            fprintf(stderr, "Fork for Child2 failed\n");
            return 1;
        }
        else if (child_pid2 == 0)
        {
            printf("Child2 process started\n");
            sleep(3);
            printf("Child2 process finished\n");
            exit(0);
        }
        else
        {
            int status1, status2;
            waitpid(child_pid1, &status1, 0);
            waitpid(child_pid2, &status2, 0);
            printf("Parent process finished\n");
        }
    }

    return 0;
}
