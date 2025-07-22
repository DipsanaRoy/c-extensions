// CE4. Check and print the entry types in Windows Systems.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("Unable to open directory");
        return 1;
    }

    struct dirent *entry;
    struct stat fileStat;
    char path[1024];

    puts("\nContents of the directory:");
    while ((entry = readdir(dir)) != NULL)
    {
        snprintf(path, sizeof(path), "%s", entry->d_name);
        if (stat(path, &fileStat) == -1)
        {
            perror("stat");
            continue;
        }

        printf("Name: %s\n", entry->d_name);
        printf("Inode: %lu\n", fileStat.st_ino);

        if (S_ISDIR(fileStat.st_mode))
            puts("Type: Directory");
        else if (S_ISREG(fileStat.st_mode))
            puts("Type: Regular File");
        else if (S_ISBLK(fileStat.st_mode))
            puts("Type: Symbolic Link");
        else
            puts("Type: Other");

        putchar("\n");
    }

    closedir(dir);
    return 0;
}
