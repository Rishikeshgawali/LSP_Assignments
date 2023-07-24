#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    printf("Application name is :\n", argv[0);
    if (argc != 2)
    {
        printf("Insufficent arguments\n");
        return -1;
    }

    const char* directory = argv[1];
    DIR* dir;
    struct dirent* entry;
    char filepath[256];
    FILE* file;

    dir = opendir(directory);

    if (dir == NULL)
    {
        printf("Error: Could not open the directory '%s'.\n", directory);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);

        file = fopen(filepath, "r");

        if (file == NULL)
        {
            printf("Error: Could not open the file '%s'.\n", filepath);
            continue;
        }

        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fclose(file);

        if (size > 100)
        {
            if (remove(filepath) == 0)
            {
                printf("File '%s' (Size: %ld bytes) deleted.\n", entry->d_name, size);
            }
            else
            {
                printf("Error: Could not delete the file '%s'.\n", entry->d_name);
            }
        }
    }

    closedir(dir);
    return 0;
}
