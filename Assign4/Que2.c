#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc , char *argv[])
{
    int dp = 0;

    printf("Appliaction name is :%s\n",argv[0]);

    if(argc != 2)
    {
        printf("Insufficent arguments:\n");
        return -1;
    }

    dp = mkdir(argv[1],0777);
    if(dp == NULL)
    {
        printf("Unablr to create the directory...\n");
        return -1;
    }

    printf("Directory is created succesfully\n");

    return 0;
}
