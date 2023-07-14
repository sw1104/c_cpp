#include <stdio.h>

// int str_len(char *s);
// int str_len2(char *s);
// int str_len3(char *s);

char *str_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - ('A' - 'a');
        }
    }

    return str;
}

void main()
{
    char *b = "HeLLo";
    char *lower = str_lower(b);
    printf("str_lower : %s\n", lower);
}

int str_length(char *str)
{
    int n = 0;
    for (char *p = str; *p != 0; p++)
    {
        n++;
    }
    return n;
}

char *a = "hello";
int len = str_length(a);
printf("str_length : %d\n", len);

// int str_len(char *s)
// {
//     int n = 0;
//     for (char *p = s; *p != 0; p++)
//     {
//         n++;
//     }
//     return n;
// }

// int str_len2(char *s)
// {
//     int n = 1;
//     for (char *p = s; *p != 0; p++)
//     {
//         n++;
//     }
//     return n;
// }

// int str_len3(char *s)
// {
//     int n = 2;
//     for (char *p = s; *p != 0; p++)
//     {
//         n++;
//     }
//     return n;
// }
