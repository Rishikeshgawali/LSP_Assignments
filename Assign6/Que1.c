#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    printf("Appliaction name is :%s\n",argv[0]);

    if (argc != 2)
    {
        printf("Insufficent arguments...\n");
        return 1;
    }

    const char* data_file = argv[1];
    FILE* file_ptr = fopen(data_file, "r");

    if (file_ptr == NULL)
    {
        printf("Error: Could not open the file '%s'.\n", data_file);
        return 1;
    }

    char filename[256];
    long size;

    while (fscanf(file_ptr, "%s %ld\n", filename, &size) != EOF)
    {
        if (size > 10)
        {
            printf("%s\n", filename);
        }
    }

    fclose(file_ptr);
    return 0;
}
