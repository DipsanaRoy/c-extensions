// CE4. Check and print the entry types in Linux and Unix Systems.
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
    DIR *dir = opendir("."); // Open current directory
    if (dir == NULL)
    {
        perror("Unable to open directory");
        return 1;
    }

    struct dirent *entry;
    puts("\nContents of the directory:");
    while ((entry = readdir(dir)) != NULL)
    {
        puts("Name: %s", entry->d_name);      // File/Directory name
        printf("Inode: %lu\n", entry->d_ino); // Print inode number

        // Check and print the entry type
        switch (entry->d_type)
        {
        case DT_DIR:
            puts("Type: Directory");
            break;
        case DT_REG:
            puts("Type: Regular File");
            break;
        case DT_LNK:
            puts("Type: Symbolic Link");
            break;
        default:
            puts("Type: Other");
        }

        printf("\nRecord Length: %d", entry->d_reclen);        // Record length
        printf("\nOffset to next entry: %ld\n", entry->d_off); // Offset to next
    }

    closedir(dir);
    return 0;
}