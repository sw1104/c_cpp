#include <stdio.h>

int str_length(char *str)
{
    int n = 0;
    for (char *p = str; *p != 0; p++)
    {
        n++;
    }
    return n;
}

int main()
{
    char *a = "hello";
    int n = str_length(a);
    printf("%d\n", n);
}