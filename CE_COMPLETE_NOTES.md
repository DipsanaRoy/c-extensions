
---

# CE2. C String Functions Cheat Sheet

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

### ✅ Example:
```c
char *text = "hello";
char *p = strchr(text, 'l');  // Points to the first 'l'
printf("%s", p);              // Output: "llo"
```

### 💡 Tips:
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

### ✅ Example:
```c
char *str = "123abc";
char *endptr;
long val = strtol(str, &endptr, 10);  // val = 123
printf("Rest: %s", endptr);           // Output: "abc"
```

### 💡 Tips:
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

### ✅ Example:
```c
char *str = "3.14pie";
char *end;
double val = strtod(str, &end);  // val = 3.14
printf("Rest: %s", end);         // Output: "pie"
```

### 💡 Tips:
- Handles scientific notation (e.g., `"1.2e3"` → `1200.0`).
- Useful for parsing user input with decimal numbers.

---

## 4. `strchr(... + 1, ch)` Tricks

You can use **nested `strchr()`** calls to find the *second, third,* etc., occurrence of a character in a string.

### ✅ Example:
```c
if (strchr(strchr(strchr(line, 'a') + 1, 'a') + 1, 'a') == NULL)
    puts(line);  // Prints if there are 2 or fewer 'a's
```

### Breakdown — Step-by-step :
1. **`strchr(lines[i], 'a')`**  
   → Finds the **first 'a'** in the string.

2. **`strchr(... + 1, 'a')`**  
   → Moves **one character after (next address by pointer arithmetic)** the first 'a', then finds the **second 'a'**.

3. **`strchr(... + 1, 'a')`**  
   → Again, moves past the second 'a', and looks for a **third 'a'**.

4. **Check `== NULL`**  
   → If the **third 'a' does not exist**, the string contains **2 or fewer 'a's**.

### ⚠️ Warning:  
If `'a'` is not found at any step, `strchr()` returns `NULL`.  
Doing `NULL + 1` causes **undefined behavior**, so use this trick **only when you’re sure the character exists enough times**, or **add checks** before deeper nesting.

---

📘 *Use these functions to search or parse strings like a pro!*

---

# CE3. File I/O

I'm glad that you've come so far! File I/O in C can be quite powerful, and there are several useful functions and techniques for various tasks. 

## Introduction:

File operations can be performed on any type of files, not limited to text files, but each file type must be treated in its own way. For example, text files store human-readable data in character or lines, while binary files contain raw data in bytes, such as images or executables.

To perform file operations correctly, you need to use appropriate file modes to ensure that the file contents are read or written properly, depending on their type. *Let's understand these to handle files effectively.*

---

## 💡 Tips:

- **"r" = read**, **"w" = write**, **"a" = append**  
- **"+" = read + write access**  
- **"b" = binary mode**

---

## 1. 📄 Key File Operation Modes

### Text File Operation Modes

*Files can be **opened** by the following modes:*

| Mode   | File Operation    | Conditions                               |
|--------|-------------------|------------------------------------------|
| `"r"`  | Read              | File must exist                          |
| `"w"`  | Write             | Overwrites or creates file               |
| `"a"`  | Append            | Creates file or appends to existing file |
| `"r+"` | Read & Write      | File must exist                          |
| `"w+"` | Read & Write      | Overwrites or creates file               |
| `"a+"` | Read & Append     | Creates file if not found, appends       |

### 🧊 Binary File Operation Modes

*Files can be **opened** by the following modes:*

| Mode   | Operation          | Conditions                                |
|--------|--------------------|-------------------------------------------|
| `"rb"` | Binary Read        | File must exist                           |
| `"wb"` | Binary Write       | Overwrites or creates file                |
| `"ab"` | Binary Append      | Creates file or appends to existing file  |
| `"rb+"`| Read & Write (bin) | File must exist                           |
| `"wb+"`| Read & Write (bin) | Overwrites or creates file                |
| `"ab+"`| Read & Append (bin)| Creates file if not found, appends        |

---

## 2. File Positioning

Functions like `fseek()` and `ftell()` are used to move around in a file and determine the current position of the file pointer. This is especially useful in both text and binary file manipulation.

---

### 🔁 `fseek()` – Move the File Position Indicator

**Syntax:**
```c
int fseek(FILE *stream, long offset, int origin);
```

Moves the file pointer to a specific byte offset from a given reference point (`origin`), allowing precise control over where reading or writing happens.

---

### 📍 Origin Constants

| Constant      | Reference Point        |
|---------------|------------------------|
| `SEEK_SET`    | Beginning of the file  |
| `SEEK_CUR`    | Current file position  |
| `SEEK_END`    | End of the file        |

> **Note:**  
> - A *positive* `offset` moves forward.  
> - A *negative* `offset` moves backward (valid with `SEEK_CUR` or `SEEK_END` only).

---

### ✅ Example Usage
```c
fseek(file, 5, SEEK_SET);   // Moves to 6th byte from start (0-based)
fseek(file, -3, SEEK_CUR);  // Moves 3 bytes back from current position
fseek(file, 0, SEEK_END);   // Moves to the end of the file
```

---

## 3. Binary File I/O: 

You can read and write binary data to files using functions like `fread` and `fwrite`. This is useful for working with non-text data or custom data structures.

---

### **`fread` and `fwrite` in Binary File I/O**

In C, **`fread`** and **`fwrite`** are used to read and write binary data to and from files. They are particularly useful for dealing with non-text data, such as images, audio files, or custom data structures.

**`fread`** reads data from a file into a buffer, and **`fwrite`** writes data from a buffer to a file.

#### Example:
```c
// Writing binary data to a file
FILE *file = fopen("data.bin", "wb");  // Open file for writing in binary mode
int num = 123;
fwrite(&num, sizeof(int), 1, file);    // Write the integer to the file
fclose(file);

// Reading binary data from a file
file = fopen("data.bin", "rb");    // Open file for reading in binary mode
fread(&num, sizeof(int), 1, file); // Read the integer from the file
fclose(file);
```

- **`fread(buffer, size_of_data, count, file)`**: Reads `count` items of `size_of_data` from the `file` into `buffer`.
- **`fwrite(buffer, size_of_data, count, file)`**: Writes `count` items of `size_of_data` from `buffer` to `file`.

---

## 4. File Validation

Before working with a file, you must check if it was opened successfully. If the file doesn’t exist or couldn’t be opened, the file pointer will be `NULL`. You should always check this to avoid errors.

### Example:
```c
FILE *file = fopen("data.txt", "r");  // Try to open the file in read mode
if (file == NULL) {  // Check if the file couldn't be opened
    perror("File not found");
    return 1;  // Exit if the file doesn't exist
}
```
- **`fopen`**: Opens the file. If it fails, it returns `NULL`, and that's why we check it.
- **`perror`**: Prints a description of the error, such as "File not found."

---

### 5. **`fflush` in File I/O**  
The **`fflush`** function is used to flush the output buffer, meaning it forces any buffered data to be written to the file immediately. This can be helpful in cases where you want to ensure that data is written to disk right away, like after a critical write operation.

**Example**:
```c
FILE *file = fopen("output.txt", "w");
fprintf(file, "Hello, World!");
fflush(file);  // Forces the data to be written to the file immediately
fclose(file);
```

- **`fflush(stdout)`**: Ensures that anything printed on the console appears immediately.
- **`fflush(stdin)`**: **Avoid this!** It’s not a standard C operation and doesn’t work reliably across compilers. Some compilers may allow it to "clear" the input buffer, but this is not portable and should be avoided.

---

## 6. String Functions in File I/O

String functions like **`strtol`**, **`strtod`**, and **`strchr`** help you work with data in files. They can convert text to numbers, search for specific characters, or filter data. This makes parsing operations like copying numbers between files or reading specific parts of a file easier.

---

## 7. File Permissions:
   Be aware of file permissions and security considerations when working with files. Ensure that your code has the necessary permissions to read/write files.

---

### Summary:

- **`fread`** and **`fwrite`** handle reading and writing binary data (e.g., images, custom data structures) to and from files.
- **File validation**: Always check if the file is opened successfully (check for `NULL`).
- **`fflush`** forces data to be written to a file or console immediately.
- **`fflush(stdout)`** ensures console output is immediately visible.
- **`fflush(stdin)`** is not standard and should be avoided.

---

## CT3. What is `*token - '0'`?

- `*token` → means the **current character** in the string (for example `'5'`, `'8'`, etc.).
- `'0'` → is the **character** `'0'`, whose **ASCII code** is **48**.

When you do `*token - '0'`, you **convert a character digit into its numeric value**.

---

### Example:

Suppose:

| Character | ASCII Value |
|:----------|:------------|
|   `'0'`   |      48     |
|   `'1'`   |      49     |
|   `'2'`   |      50     |
|   `'3'`   |      51     |
|   `'4'`   |      52     |
|   `'5'`   |      53     |
|   `'6'`   |      54     |
|   `'7'`   |      55     |
|   `'8'`   |      56     |
|   `'9'`   |      57     |

If `*token = '5'`, then:

```
*token - '0'
= '5' - '0'
= 53 - 48
= 5
```

✅ So `'5'` (character) becomes `5` (integer) — **perfect for calculation**!

---

## Why do we need it?

Because when reading from a string, digits are **characters**, not numbers.  
You **have to convert them** if you want to build the final number.

Otherwise, you would be mistakenly adding ASCII codes!

---

### 🌟 Visual:

| What you have (char) | What you need (int) | How to get  |
|:---------------------|:--------------------|:------------|
| `'7'` (char)         | `7` (number)        | `'7' - '0'` |

---

## ⚡ Final shortcut memory tip:

> **Characters '0' to '9' are in order** in ASCII.  
> Subtracting `'0'` **normalizes** them to real numbers `0` to `9`.

---

## 📁 CE4 – Directory Handling in C

This mini-guide helps you learn how to **open**, **read**, **change**, and **close** directories using C. Great for beginners exploring how files and folders work programmatically!

---

### 🛣️ What is a "Path"?

A **path** is like an address to a folder or file on your computer.

- `"."` → current folder  
- `".."` → one level up (parent folder)  
- `"D:/Folder/Subfolder"` → full (absolute) path on Windows  
- `"../Folder"` → relative path from the current location

---

### 📌 Functions Overview

| Function             | Purpose                               | Header         |
|----------------------|---------------------------------------|----------------|
| `opendir(path)`      | Opens a directory stream              | `<dirent.h>`   |
| `readdir(dir)`       | Reads entries from a directory        | `<dirent.h>`   |
| `closedir(dir)`      | Closes the opened directory           | `<dirent.h>`   |
| `chdir(path)`        | Changes the current working directory | `<unistd.h>`   |
| `struct dirent*`     | Holds info about a directory entry    | `<dirent.h>`   |
| `entry->d_name`      | Gets the name of the file/folder      | `<dirent.h>`   |

---

### ✅ Example 1: Open, Read, Close a Directory

```c
DIR *dir = opendir("your_path_here");
struct dirent *entry;

while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}

closedir(dir);
```

🖨️ **Sample Output**:
```
.
..
main.c
data.txt
folder1
```

> ⚠️ **Note:**  
> `"."` = current directory  
> `".."` = parent directory  

---

### ✅ Example 2: Change Working Directory & Read It

```c
if (chdir("path/to/your/directory") == 0) {
    DIR *dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closedir(dir);
} else {
    perror("Changing directory failed");
}
```

🎯 **Use Case**: Navigate into another folder at runtime before listing files.

---

### 💡 Tips

- Always check if `opendir()` or `readdir()` returns `NULL`.
- For filtering files only:  
  Add a condition like `strchr(entry->d_name, '.')` or use string comparison.
- `chdir("..")` helps go **up one level** in the directory tree.

---

# CE4. 📚 Linux Filesystem: Device Types, Inodes, and File Information

---

## 📦 Common `d_type` Values on Linux

In **Linux**, the `DT_BLK` (**Directory Type: Block Device**) is defined in `dirent.h`.

| Macro        | Meaning                                       |
|:-------------|:----------------------------------------------|
| `DT_REG`     | Regular file (normal file)                    |
| `DT_DIR`     | Directory                                      |
| `DT_LNK`     | Symbolic link (shortcut)                      |
| `DT_BLK`     | Block device (e.g., HDD, SSD, USB storage)     |
| `DT_CHR`     | Character device (e.g., keyboard, mouse)       |
| `DT_FIFO`    | Named pipe (FIFO special file)                 |
| `DT_SOCK`    | Socket file (for network communication)        |
| `DT_UNKNOWN` | Unknown type (if info not available)           |

---

## 🛜 Linux Filesystem View

Linux **treats everything as a file**, including:
- Storage devices (block devices)
- Serial ports (character devices)
- Pipes (communication channels)
- Network sockets

Thus, Linux has macros like **DT_BLK**, **DT_CHR**, **DT_FIFO**, etc., to *differentiate* between these device types.

> **Meanwhile**, Windows keeps it simple: only **File** or **Directory** are exposed (even though NTFS internally supports complex types).

---

## 🔥 Summary

👉 **Yes, `DT_BLK` exists in Linux** because Linux's filesystem design treats **devices as files**.

---

## What is an Inode?

- **Inode** (short for "index node") is a **data structure** used in filesystems (Linux/Unix) to **store metadata** about files and directories.
- **It stores:**
  - File size
  - Owner
  - Permissions
  - Timestamps
  - **Not the filename** (filename is stored separately)

🔸 **Think of an inode** as a *unique ID* pointing to a file’s actual data.

> **Note:** Windows does **not** have a true inode concept. So, `d_ino` fields are meaningless there.

---

## 🛡️ S_ISDIR, S_ISREG, and Other Macros

These **macros** are used to **check the type of a file** based on file mode information from `stat()`.

| Macro           | Checks for           |
|:----------------|:---------------------|
| `S_ISDIR(mode)` | Directory            |
| `S_ISREG(mode)` | Regular file         |
| `S_ISLNK(mode)` | Symbolic link (soft link) |

Example:
```c
if (S_ISDIR(fileStat.st_mode)) {
    printf("It's a directory!\n");
}
```

---

## What is `stat()`?

- `stat()` is a **system call** that **fetches information about a file** (size, permissions, type, etc).
- It fills a `struct stat` with many fields.

Example:
```c
struct stat fileStat;
stat("myfile.txt", &fileStat);
```

**Important fields:**
- `fileStat.st_size` ➔ Size in bytes
- `fileStat.st_mode` ➔ Type and permission bits
- `fileStat.st_ino` ➔ Inode number (valid mainly in Unix/Linux)

---

## ⚡ Quick Recap Table

| Term         | Meaning                                           |
|:-------------|:--------------------------------------------------|
| `perror()`   | Auto-prints error message + newline.               |
| Inode        | File metadata pointer (only Unix/Linux).           |
| `S_ISDIR`, etc. | Macros to check file type from `stat()` info. |
| `stat()`     | System call to get detailed file info.             |

---

## 🚀 Who Needs to Know This?

- System-level programmers
- OS developers
- Filesystem developers
- Driver developers
- Backup, recovery, and security software developers
- Power-user tools (`ls`, `cp`, `rsync`, `find`, etc.)
- Custom server developers

---

## 📚 S_ISBLK and S_ISLNK: Windows vs Linux

| Macro        | Meaning                           | Windows Support | Linux Support |
|:-------------|:----------------------------------|:----------------|:--------------|
| `S_ISBLK`    | Block device (e.g., HDD, SSD)      | ❌ (Not real block files) | ✅ |
| `S_ISLNK`    | Symbolic link                      | ❌ (No real Unix-like symlinks) | ✅ |

> Windows **does not fully** implement Unix-style features like **block devices** or **true symbolic links**.

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
<!-- CE6 -->
---

# 1. Logical OR (`||`) vs Bitwise OR (`|`) in Recursion

| Operator | Behavior                | Short-Circuits?        | Evaluates Both? |
|----------|-------------------------|------------------------|-----------------|
| `||`     | Logical OR (true/false) | ✅ Yes (Stops if true) | ❌ No          |
| `|`      | Bitwise OR (bit-by-bit) | ❌ No                  | ✅ Yes         |

## Example (Logical OR `||`):
```c
if (funcA() || funcB()) {
    // funcB() called only if funcA() returns 0
}
```

## Example (Bitwise OR `|`):
```c
if (funcA() | funcB()) {
    // Both funcA() and funcB() are called
}
```

### Important:
- Infinite recursion can happen if **no function returns true** and you don't handle the base case properly! ⚡

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
