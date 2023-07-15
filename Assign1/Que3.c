#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    int fd = 0;
    int Mode = 0;

    printf("Application name is :%s\n",argv[0]);

    if(argc != 3)
    {
        printf("Invalid number of argument\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = O_RDONLY;
    }

    if(strcmp(argv[2],"Write") == 0)
    {
        Mode = O_WRONLY;
    }

    if(strcmp(argv[2],"ReadWrite") == 0)
    {
        Mode = O_RDWR;
    }

    fd = access(argv[1],Mode);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    printf("File is succesfully opend with this mode,FD:%d\n",fd);



    return 0;
}
