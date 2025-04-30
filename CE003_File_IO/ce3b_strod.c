// CE3. Read double numbers & text from a file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

int main()
{
    // Init: Token & File Pointer
    FILE *fptr = fopen("mixed_data.txt", "r");
    char token[100];

    if (fptr == NULL)
    {
        perror("File not found");
        return -1;
    }

    putchar('\n');
    while (fscanf(fptr, "%s", token) == 1)
    {
        char *endChar;
        double num = strtod(token, &endChar); // strtod [string to double] converts double-strings to double

        if (*endChar == '\0' && token != endChar)
            printf("Found number: %.4f\n", num);
        else
            printf("Found text: %s\n", token);
    }
    return 0;
}