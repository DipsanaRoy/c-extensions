// CE3. Fetch file length
#include <stdio.h>

// Function Prototype
long getFileLength(FILE *file);

int main()
{
    FILE *file = fopen("example.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    printf("File length: %ld bytes.\n", getFileLength(file));
    fclose(file);
    return 0;
}

// Function Definition
long getFileLength(FILE *file)
{
    fseek(file, 0, SEEK_END);  // Moves file pointer to the file end
    long length = ftell(file); // Get the current position (file size)
    fseek(file, 0, SEEK_SET);  // Moves file pointer to the file start
    return length;
}