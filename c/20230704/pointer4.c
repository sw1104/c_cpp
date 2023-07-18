#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *b = &a;

    printf("%d\n", b[2]);

    return 0;
}

108 101 101 115 97 110 103 119 111 111