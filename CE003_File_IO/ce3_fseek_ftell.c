// CE3. fseek and ftell
#include <stdio.h>

int main()
{
    FILE *file = fopen("example.html", "r");
    if (file == NULL)
    {
        perror("File not found");
        return 1;
    }

    fseek(file, 0, SEEK_SET);    // sets 'reference point' to 'file start'
    long position = ftell(file); // gets 'current position' i.e. 0

    printf("\nCurrent position: %ld", position);
    printf("\nFile content: %c\n", fgetc(file)); // Reads 1st character

    fseek(file, 1, SEEK_SET); // moves 'position indicator' from 'file start'
    position = ftell(file);   // to 1

    printf("\nCurrent position: %ld", position);
    printf("\nFile content: %c\n", fgetc(file)); // Reads 2nd character

    fseek(file, 3, SEEK_CUR); // moves 'position indicator' after 'current file position'
    position = ftell(file);   // to 5

    printf("\nCurrent position: %ld", position);
    printf("\nFile content: %c\n", fgetc(file)); // Reads 6th character

    fseek(file, 0, SEEK_END);                       // moves 'position indicator' to file end.
    printf("\nCurrent position: %ld", ftell(file)); // Reads file end i.e. EOF [blank]
    printf("\nFile content: %c\n", fgetc(file));

    fclose(file);
    return 0;
}