#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    printf("Appliacation name is :%s\n",argv[0])

    if(argc != 3)
    {
        printf("Insufficent argument , correct arguments : 3\n");
        return 0;
    }

    int no1 = 0;
    int no2 = 0;
    int Ans = 0;

    scanf("%d",no1);
    scanf("%d",no2);

    Ans = no1 + no2;

    printf(Ans);

    return 0;
}
