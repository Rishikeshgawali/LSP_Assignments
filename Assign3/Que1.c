#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int ret = 0;
    int pd1 = 0;
    int pd2 = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    pd1 = open(argv[1],O_RDONLY);
    if(pd1 == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    ret = read(pd1,Buffer,BLOCKSIZE);
    if(ret == 0)
    {
        printf("Unable to read from file\n");
        return -1;
    }

    pd2 = open(argv[2],O_RDWR);
    if(pd2 == -1)
    {
        printf("Unable  to open destination file");
    }

    write(pd2,Buffer,BLOCKSIZE);


    return 0;
}
