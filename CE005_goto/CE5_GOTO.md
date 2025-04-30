
---

# CE5. `goto` Statement in C

## Definition:  
`goto` is a control statement used to **jump to a labeled part** of the program.

## Syntax:
```c
goto label;
// ...
label:
    // Code to execute
```

### Example:
```c
#include <stdio.h>

int main() {
    int x = 5;

    if (x < 10) {
        goto label;
    }
    printf("This will be skipped!\n");

label:
    printf("Jumped to the label!\n");
    return 0;
}
```

### Output:
```
Jumped to the label!
```

## Why `goto` is Controversial?
- ❌ Makes code hard to read ("spaghetti code").
- ❌ Harder debugging and tracing.
- ✅ Sometimes useful for error handling in C.

## Pro Tip:
✨ Avoid using `goto` unless absolutely necessary!

---
