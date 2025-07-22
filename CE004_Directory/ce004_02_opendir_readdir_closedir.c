// CE4. Let's open, read and close a directory.
#include <stdio.h>
#include <dirent.h>

int main()
{
    const char *path = "D:/Coding/C/learn-c-with-practice0000/Extensions_C"; // provide the directory's 'relative' or 'full' path
    
    DIR *dir = opendir(path); // 'Open' the directory
    if (dir == NULL)
    {
        perror("Directory opening failed");
        return 1;
    }

    // 'Read' the directory
    struct dirent *entry;
    puts("\nEntry names:");
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name); // d_name: directory name
    }

    closedir(dir); // 'Close' the directory
    return 0;
}


