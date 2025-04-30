
---

# CE7. Absolute Value Functions in C

| Function   | Works With      | Header       |
|------------|-----------------|--------------|
| `abs(x)`   | `int`           | `<stdlib.h>` |
| `labs(x)`  | `long int`      | `<stdlib.h>` |
| `llabs(x)` | `long long int` | `<stdlib.h>` |
| `fabs(x)`  | `double`        | `<math.h>`   |
| `fabsf(x)` | `float`         | `<math.h>`   |
| `fabsl(x)` | `long double`   | `<math.h>`   |

## Example:
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a = -10;
    double d = -5.67;

    printf("%d\n", abs(a));
    printf("%.2f\n", fabs(d));

    return 0;
}
```

---
