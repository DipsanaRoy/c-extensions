// CE3.6. Read long numbers & text from a file
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
        long num = strtol(token, &endChar, 10); // strtol [string to long] converts long-strings to long by base (10 here: decimal)

        if (*endChar == '\0' && token != endChar)
            printf("Found number: %d\n", num);
        else
            printf("Found text: %s\n", token);
    }
    return 0;
}
