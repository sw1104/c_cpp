#include <stdio.h>

void str_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - ('A' - 'a');
        }
    }
}

void main()
{
    char str[] = "HelLo";
    printf("Before: %s\n", str);

    str_lower(str);
    printf("After: %s\n", str);

    // return 0;
}