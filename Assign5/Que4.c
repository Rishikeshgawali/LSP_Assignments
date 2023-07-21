#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    const char* directory = argv[1];

    DIR* dir;
    struct dirent* entry;

    dir = opendir(directory);
    if (dir == NULL)
    {
        printf("Error opening directory");
        return -1;
    }

    int fd1 = open("AllCombine", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd1 < 0)
    {
        printf("Error creating/opening output file");
        closedir(dir);
        return 1;
    }

    char buffer[BLOCKSIZE];

    while ((entry = readdir(dir)) != NULL)
    {
        char filepath[256];

        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
        int fd2 = open(filepath, O_RDONLY);
        if (fd2 < 0)
        {
            printf("Error opening input file");
            continue;
        }

        ssize_t bytes_read;
        while ((bytes_read = read(fd2, buffer, BLOCKSIZE)) > 0)
        {
            ssize_t bytes_written = write(fd1, buffer, bytes_read);
            if (bytes_written < 0)
            {
                printf("Error writing to output file");
                close(fd2);
                close(fd1);
                closedir(dir);
                return -1;
            }
        }

        if (bytes_read < 0)
        {
            printf("Error reading from file");
            close(fd2);
            continue;
        }

        close(fd2);
    }

    close(fd1);
    closedir(dir);

    return 0;
}
