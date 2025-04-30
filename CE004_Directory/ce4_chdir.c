// CE4. Let's change a directory
#include <stdio.h>
#include <dirent.h>
#include <unistd.h> // For chdir function

int main()
{
    if (chdir("path/to/your/directory"))
    {
        perror("Changing directory failed");
        return 1;
    }
    // The current working directory has been changed.
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("Directory opening failed");
        return 1;
    }

    // Work with the directory here.

    closedir(dir);
    return 0;
}