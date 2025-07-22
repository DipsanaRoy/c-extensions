/* CE3.1. Let's open "mylog.txt" file in 'append' mode, and use `fprintf` to add a new line to the file's end.
     The existing content remains intact, and the new data is appended to it. */

#include <stdio.h>

int main()
{
    FILE *file = fopen("mylog.txt", "a"); // 'Open' file in 'append' mode

    if (file == NULL)
    {
        perror("Error");
        return 1;
    }

    fprintf(file, "This is a new line added to the end of the file.\n");
    fclose(file);
    return 0;
}
