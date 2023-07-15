#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc , char *argv[])
{
    int fd = 0;

    printf("Application name is : %s\n",argv[0]);
    if(argc != 2)
    {
        printf("Invalid number of argument\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    printf("File is succesfilly opend with FD :%d\n",fd);

    return 0;
}
