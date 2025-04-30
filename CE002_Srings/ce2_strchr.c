// CE2. Show only strings which contains no more than two 'a'
#include <stdio.h>
#include <string.h>

int main()
{
    char *lines[] = {
        "Hello! I am a String.",
        "String says everyone to keep their curiosity alive.",
        "Amazingly, banana paradise awaits Alaba at Alabama."
    };

    for (int i = 0; i < 3; i++)
    {
        if (strchr(strchr(strchr(lines[i], 'a') + 1, 'a') + 1, 'a') == NULL)
            puts(lines[i]);
    }
    return 0;
}