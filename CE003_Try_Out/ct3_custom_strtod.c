// CE3. Read double numbers & text from a file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for digit()
#include <math.h>  // for pow()
#include <errno.h>
#include <stdarg.h>

// Function Prototypes
int print(const char *format, ...);
double str_to_double(char *token, char **endChar);

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

    print("\n");
    while (fscanf(fptr, "%s", token) == 1)
    {
        char *endChar;
        double num = str_to_double(token, &endChar);

        if (*endChar == '\0' && token != endChar)
            print("Found double: %f\n", num);
        else
            print("Found text: %s\n", token);
    }
    fclose(fptr);
    return 0;
}

// Function Definitions

// Safe Print: from c-error-handling
int print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);

    if (result < 0)
    {
        perror("Logging failure");
        return -1;
    }
    return result;
}

// Robust String to Double Converter
double str_to_double(char *token, char **endChar)
{
    double num = 0.0;
    int neg = 0;
    int seen_dot = 0, seen_digit = 0;
    char *t = token;

    // Handle sign
    if (*t == '-')
    {
        neg = 1;
        t++; // Move past the sign
    }
    else if (*t == '+')
        t++;

    // Integer and decimal part
    for (; *t; t++)
    {
        if (isdigit(*t))
        {
            num = num * 10 + (*t - '0'); // *t - '0' = number discussed in CT3_NOTES.md
            seen_digit = 1;
        }
        else if (*t == '.')
        {
            // Multiple dots invalid
            if (seen_dot)
                break;
            seen_dot = 1;
            t++; // Move past the dot
            
            double frac = 0.0, scale = 0.1;
            while (isdigit(*t))
            {
                frac += (*t - '0') * scale;
                scale *= 0.1;
                seen_digit = 1;
                t++;
            }
            num += frac;
        }
        else
            break;
    }

    // Exponent part
    if ((*t == 'e' || *t == 'E'))
    {
        t++;
        int exp_sign = 1, exp_val = 0;
        if (*t == '-')
        {
            exp_sign = -1;
            t++;
        }
        else if (*t == '+')
            t++;

        if (!isdigit(*t))
        {
            *endChar = t;
            return -1;
        }

        while (isdigit(*t))
        {
            exp_val = exp_val * 10 + (*t - '0');
            t++;
        }
        num *= pow(10, exp_sign * exp_val);
    }

    *endChar = t;
    if (!seen_digit)
        return -1;

    return neg ? -num : num;
}