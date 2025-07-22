// CE1.1. Count number of digits in a number
#include <stdio.h>

int count_digits(int num)
{
    if (num == 0) return 1;
    int count = 0;
    for (; num != 0; count++) // Init & Update can be skipped in a for loop
    {
        num /= 10;
    }
    return count;
}

int main()
{
    int number;
    printf("\nEnter an integer: ");
    scanf("%d", &number);

    int digits = count_digits(number);
    printf("The number %d has %d digit%s.\n", number, digits, (digits > 1 ? "s" : ""));
    return 0;
}
