# 📁 CE004 – Directory Handling in C

This mini-guide helps you learn how to **open**, **read**, **change**, and **close** directories using C. Great for beginners exploring how files and folders work programmatically!

---

## 🛣️ What is a "Path"?

A **path** is like an address to a folder or file on your computer.

- `"."` → current folder  
- `".."` → one level up (parent folder)  
- `"D:/Folder/Subfolder"` → full (absolute) path on Windows  
- `"../Folder"` → relative path from the current location

---

## 📌 Functions Overview

| Function             | Purpose                               | Header         |
|----------------------|---------------------------------------|----------------|
| `opendir(path)`      | Opens a directory stream              | `<dirent.h>`   |
| `readdir(dir)`       | Reads entries from a directory        | `<dirent.h>`   |
| `closedir(dir)`      | Closes the opened directory           | `<dirent.h>`   |
| `chdir(path)`        | Changes the current working directory | `<unistd.h>`   |
| `struct dirent*`     | Holds info about a directory entry    | `<dirent.h>`   |
| `entry->d_name`      | Gets the name of the file/folder      | `<dirent.h>`   |

---

## ✅ Example 1: Open, Read, Close a Directory

```c
DIR *dir = opendir("your_path_here");
struct dirent *entry;

while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}

closedir(dir);
```

🖨️ **Sample Output**:

```text
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

## ✅ Example 2: Change Working Directory & Read It

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

## 💡 Tips

- Always check if `opendir()` or `readdir()` returns `NULL`.
- For filtering files only:  
  Add a condition like `strchr(entry->d_name, '.')` or use string comparison.
- `chdir("..")` helps go **up one level** in the directory tree.

---
