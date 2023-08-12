#include <stdio.h>
#include <sys/resource.h>

int main()
{
    int priority = getpriority(PRIO_PROCESS, 0);

    if (priority == -1)
    {
        printf("getpriority");
        return -1;
    }

    printf("Priority of the process is: %d\n",priority);

    return 0;
}
