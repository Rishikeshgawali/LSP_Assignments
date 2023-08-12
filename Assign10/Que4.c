#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ThreadData
{
    int input_value;
    int result_value;
};

void *thread_function(void *arg)
{
    struct ThreadData *data = (struct ThreadData *)arg;
    printf("Thread started: Input value is %d\n", data->input_value);

    data->result_value = data->input_value * 2;

    return NULL;
}

int main()
{
    pthread_t thread_id;
    struct ThreadData thread_data;

    printf("Main program started\n");

    printf("Enter a value: ");
    scanf("%d", &thread_data.input_value);

    if (pthread_create(&thread_id, NULL, thread_function, &thread_data) != 0)
    {
        printf("pthread_create");
        return -1;
    }

    if (pthread_join(thread_id, NULL) != 0)
    {
        printf("pthread_join");
        return -1;
    }

    printf("Thread finished: Result value is %d\n", thread_data.result_value);

    printf("Main program finished\n");

    return 0;
}
