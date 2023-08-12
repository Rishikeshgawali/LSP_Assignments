#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *arg)
{
    int parameter = *(int *)arg;
    printf("Given parameter is: %d\n", parameter);
    return NULL;
}

int main()
{
    pthread_t thread_id;
    int ino = 11;

    if (pthread_create(&thread_id, NULL, thread, &ino) != 0)
    {
        printf("pthread_create");
        return -1;
    }

    if (pthread_join(thread_id, NULL) != 0)
    {
        printf("pthread_join");
        return -1;
    }

    printf("Thread finished\n");

    return 0;
}
