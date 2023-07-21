#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int EID;
    char Ename[20];
    char Pos[20];
    char Project[20];
};

int main(int argc, char *argv[])
{
    struct Employee sobj;
    char Fname[20];
    int fd = 0;

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Name of Employee : %s : \n",sobj.Ename);
    printf("Office ID : %d : \n",sobj.EID);
    printf("Position : %s : \n",sobj.Pos);
    printf("Current project : %s : \n",sobj.Project);

    close(fd);

    return 0;
}
