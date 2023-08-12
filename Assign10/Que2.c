#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 500

void *print_up(void *arg)
{
    for (int i = 1; i <= MAX; ++i)
    {
        printf("Thread 1: %d\n", i);
    }
    return NULL;
}

void *print_down(void *arg)
{
    for (int i = MAX; i >= 1; --i)
    {
        printf("Thread 2: %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    printf("Main program started\n");

    if (pthread_create(&thread1, NULL, print_up, NULL) != 0)
    {
        printf("pthread_create for Thread 1");
        return -1;
    }

    if (pthread_create(&thread2, NULL, print_down, NULL) != 0)
    {
        printf("pthread_create for Thread 2");
        return -1;
    }

    if (pthread_join(thread1, NULL) != 0)
    {
        printf("pthread_join for Thread 1");
        return -1;
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        printf("pthread_join for Thread 2");
        return -1;
    }

    printf("Both threads finished\n");

    return 0;
}
