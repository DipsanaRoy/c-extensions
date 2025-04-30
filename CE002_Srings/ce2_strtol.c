// CE2. Convert a long-strings to long
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "123abc";
    char *end;
    long val = strtol(str, &end, 10); // base 10

    printf("Converted number: %ld\n", val);     // 123
    printf("Remaining text: %s\n", end);        // abc
    return 0;
}