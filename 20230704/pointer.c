#include <stdio.h>

int main(void)
{
    int a = 0;
    int *b = &a;
    printf("%d\n", *b);
    return 0;
}