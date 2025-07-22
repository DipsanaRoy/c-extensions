# CE003. File I/O

I'm glad that you've come so far! File I/O in C can be quite powerful, and there are several useful functions and techniques for various tasks.

## Introduction

File operations can be performed on any type of files, not limited to text files, but each file type must be treated in its own way. For example, text files store human-readable data in character or lines, while binary files contain raw data in bytes, such as images or executables.

To perform file operations correctly, you need to use appropriate file modes to ensure that the file contents are read or written properly, depending on their type. *Let's understand these to handle files effectively.*

---

## 💡 Tips

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
>
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

## 3. Binary File I/O

You can read and write binary data to files using functions like `fread` and `fwrite`. This is useful for working with non-text data or custom data structures.

---

### **`fread` and `fwrite` in Binary File I/O**

In C, **`fread`** and **`fwrite`** are used to read and write binary data to and from files. They are particularly useful for dealing with non-text data, such as images, audio files, or custom data structures.

**`fread`** reads data from a file into a buffer, and **`fwrite`** writes data from a buffer to a file.

#### Example

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

### Example

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

## 7. File Permissions

   Be aware of file permissions and security considerations when working with files. Ensure that your code has the necessary permissions to read/write files.

---

### Summary

- **`fread`** and **`fwrite`** handle reading and writing binary data (e.g., images, custom data structures) to and from files.
- **File validation**: Always check if the file is opened successfully (check for `NULL`).
- **`fflush`** forces data to be written to a file or console immediately.
- **`fflush(stdout)`** ensures console output is immediately visible.
- **`fflush(stdin)`** is not standard and should be avoided.

---
