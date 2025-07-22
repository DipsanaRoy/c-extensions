// CE3.8. Read double, long numbers & text from a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        {
            if (strchr(token, '.') || strchr(token, 'e') || strchr(token, 'E')) // returns >0 if specified char is found in the string
            {
                printf("Found double: %.4f\n", num);
            }
            else
                printf("Found long: %ld\n", (long)num);
        }
        else
            printf("Found text: %s\n", token);
    }
    return 0;
}
