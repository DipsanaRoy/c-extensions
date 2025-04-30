// CE2. Convert a double-string to double
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "3.14pi";
    char *end;
    double val = strtod(str, &end);

    printf("Converted number: %f\n", val);      // 3.140000
    printf("Remaining text: %s\n", end);        // pi
    return 0;
}