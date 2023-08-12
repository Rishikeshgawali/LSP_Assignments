#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg)
{
    printf("Thread is running\n");
    return NULL;
}

int main()
{
    pthread_t thread_id;

    printf("Main program started\n");

    if (pthread_create(&thread_id, NULL, thread1, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    printf("Thread created\n");

    if (pthread_join(thread_id, NULL) != 0)
    {
        printf("Error pthread join");
        return -1;
    }

    return 0;
}
