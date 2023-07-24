#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("Appliaction name is:", argv[0]);

    if (argc != 3)
    {
        printf("Insuffecient arguments\n"]);
        return -11;
    }

    const char* directory = argv[1];
    const char* filename = argv[2];
    char filepath[256];
    FILE* file;

    snprintf(filepath, sizeof(filepath), "%s/%s", directory, filename);

    file = fopen(filepath, "w");

    if (file == NULL)
    {
        printf("Unacle to create the file '%s' in '%s'.\n", filename, directory);
        return 1;
    }
    else
    {
        fclose(file);
        printf("File '%s' created in '%s'.\n", filename, directory);
    }

    return 0;
