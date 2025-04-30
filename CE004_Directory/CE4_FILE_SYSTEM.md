
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
