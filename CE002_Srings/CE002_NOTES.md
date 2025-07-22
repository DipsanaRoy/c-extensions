# CE002. C String Functions Cheat Sheet

This mini-guide covers three useful C standard library functions for handling strings and converting them to numbers: `strchr()`, `strtol()`, and `strtod()`.

---

## 1. `strchr()`

**Purpose**: Find the *first occurrence* of a character in a string.

```c
#include <string.h>

char *strchr(const char *str, int ch);
```

**How it works**:  
Scans `str` for the character `ch` and returns a pointer to the *first match*.

### ✅ Example

```c
char *text = "hello";
char *p = strchr(text, 'l');  // Points to the first 'l'
printf("%s", p);              // Output: "llo"
```

### 💡 Tips

- Returns `NULL` if the character isn’t found.
- Can be used to split or search strings easily.

---

## 2. `strtol()`

**Purpose**: Convert a string to a `long int`.

```c
#include <stdlib.h>

long strtol(const char *str, char **endptr, int base);
```

**How it works**:  
Reads characters in `str` until it hits a non-number (or end), converts them to a long integer using the specified `base`.

### ✅ Example

```c
char *str = "123abc";
char *endptr;
long val = strtol(str, &endptr, 10);  // val = 123
printf("Rest: %s", endptr);           // Output: "abc"
```

### 💡 Tips

- Use `endptr` to find out where the number parsing stopped.
- Common `base` values: `10` (decimal), `16` (hex), `0` (auto-detects base like `0x` or `0`).

---

## 3. `strtod()`

**Purpose**: Convert a string to a `double`.

```c
#include <stdlib.h>

double strtod(const char *str, char **endptr);
```

**How it works**:  
Similar to `strtol`, but handles floating-point numbers.

### ✅ Example

```c
char *str = "3.14pie";
char *end;
double val = strtod(str, &end);  // val = 3.14
printf("Rest: %s", end);         // Output: "pie"
```

### 💡 Tips

- Handles scientific notation (e.g., `"1.2e3"` → `1200.0`).
- Useful for parsing user input with decimal numbers.

---

## 4. `strchr(... + 1, ch)` Tricks

You can use **nested `strchr()`** calls to find the *second, third,* etc., occurrence of a character in a string.

### ✅ Example

```c
if (strchr(strchr(strchr(line, 'a') + 1, 'a') + 1, 'a') == NULL)
    puts(line);  // Prints if there are 2 or fewer 'a's
```

### Breakdown — Step-by-step

1. **`strchr(lines[i], 'a')`**  
   → Finds the **first 'a'** in the string.

2. **`strchr(... + 1, 'a')`**  
   → Moves **one character after (next address by pointer arithmetic)** the first 'a', then finds the **second 'a'**.

3. **`strchr(... + 1, 'a')`**  
   → Again, moves past the second 'a', and looks for a **third 'a'**.

4. **Check `== NULL`**  
   → If the **third 'a' does not exist**, the string contains **2 or fewer 'a's**.

### ⚠️ Warning  

If `'a'` is not found at any step, `strchr()` returns `NULL`.  
Doing `NULL + 1` causes **undefined behavior**, so use this trick **only when you’re sure the character exists enough times**, or **add checks** before deeper nesting.

---

📘 *Use these functions to search or parse strings like a pro!*
