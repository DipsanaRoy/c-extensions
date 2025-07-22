// CE3.3. Binary read input file data and write it to the output file.
#include <stdio.h>

int main()
{
    FILE *input = fopen("input.txt", "rb");   // Open for binary read
    FILE *output = fopen("output.txt", "wb"); // Open for binary write

    if (input == NULL || output == NULL)
    {
        perror("File opening failed");
        return 1;
    }

    char buffer[1024]; // Here: buffer refers to file buffer.
    size_t bytes_read;

    // Write input file data to output file.
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), input)) > 0)
    {
        fwrite(buffer, sizeof(char), bytes_read, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}
