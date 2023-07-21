#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCKSIZE 10

int main(int argc , char *argv[])
{

    char DirName[256];

    printf("Enter the directory name: ");
    scanf("%s", DirName);


    DIR* dir;
    struct dirent* entry;

    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("Unable to open Directory");
        return;
    }

    int fd1 = open("combined_data.txt", O_CREAT | O_WRONLY, 0666);

    if (fd1 < 0)
    {
        printf("Unablr to open\n");
        closedir(dir);
        return -1;
    }

    char buffer[BLOCKSIZE];
    while ((entry = readdir(dir)) != NULL)
    {
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);

        int fd2 = open(filepath, O_RDONLY);

        if (fd2 < 0)
        {
            printf("Error opening input file");
            continue;
        }

        int bytes_read = read(fd2, buffer, BLOCKSIZE);

        if (bytes_read < 0)
        {
            printf("Error reading from file");
            close(fd2);
            continue;
        }


        int bytes_written = write(fd1,buffer,bytes_read);

        if (bytes_written < 0)
        {
            printf("Unable writing to output file\n");
            close(fd2);
            break;
        }

        close(fd2);
    }

    close(fd1);
    closedir(dir);
}
