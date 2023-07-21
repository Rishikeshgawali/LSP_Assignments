include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[]) {

    if (argc != 2)
    {
        printf("Insufficent arguments", argv[0]);
        return 1;
    }

    const char* input_file = argv[1];
    int fd1 = open(input_file, O_RDONLY);

    if (fd1 < 0)
    {
        printf("Error opening input file: %s\n", input_file);
        return 1;
    }

    char buffer[BLOCKSIZE];
    int fd2;
    ssize_t bytes_read;

    while ((bytes_read = read(fd1, buffer, BLOCKSIZE)) > 0)
    {
        char* filename = strtok(buffer, "\n");
        char* content = strtok(NULL, "\n");

        if (filename && content)
        {
            fd2 = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
            if (fd2 < 0)
            {
                printf("Error creating/opening output file: %s\n", filename);
                close(fd1);
                return 1;
            }

            ssize_t bytes_written = write(fd2, content, strlen(content));
            if (bytes_written < 0)
            {
                printf("Error writing to output file: %s\n", filename);
                close(fd1);
                close(fd2);
                return 1;
            }

            close(fd2);
        }
    }

    if (bytes_read < 0)
    {
        printf("Error reading from input file: %s\n", input_file);
        close(fd1);
        return 1;
    }

    close(fd1);

    return 0;
}
