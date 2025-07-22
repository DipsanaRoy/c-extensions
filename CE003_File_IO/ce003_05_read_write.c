// CE3.5. Modify an integer containing file to double its value.
#include <stdio.h>

int main()
{
    int num; // store integer

    FILE *ptr = fopen("sample.txt", "r+"); // Open file by Read and Write (file must exist)
 // FILE *ptr = fopen("sample.txt", "w+"); // Open file by Read and Write (create or overwrite)

    fscanf(ptr, "%d", &num);     // Read an integer
    fprintf(ptr, "%d", num * 2); // Doubles the integer

    fclose(ptr); // Close the file
    printf("\nDoubled %d to %d\n", num, num * 2);
    return 0;
}
