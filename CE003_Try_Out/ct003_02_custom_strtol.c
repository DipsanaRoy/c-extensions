// CE3. Read long decimal numbers & text from a file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

// Function Prototype
long str_to_long(char *token, char **endChar);

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
        long num = str_to_long(token, &endChar);

        if (*endChar == '\0' && token != endChar)
            printf("Found long: %ld\n", num);
        else
            printf("Found text: %s\n", token);
    }
    return 0;
}

// Function Definition

// converts long-strings to long
long str_to_long(char *token, char **endChar)
{
    long num = 0;
    int neg = 0, notNum = 0;
    char *start = token;

    if (*token == '-')
    {
        neg = 1;
        token++;
    }
    else if (*token == '+')
        token++;

    // convert string-long to long    
    for (; *token != '\0'; token++)
    {
        switch (*token)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            num = num * 10 + (*token - '0'); // *token - '0' = number discussed in CT3_NOTES.md
            break;
        default:
            *endChar = token;
            return neg ? -num : num;
        }

        *endChar = token; // endChar points to where parsing stooped

        // ❗ No digits case
        if (start == token || (neg && start + 1 == token))
        {
            *endChar = start;
            return -1;
        }
        return neg ? -num : num;
    }
}
