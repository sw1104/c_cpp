#include <stdio.h>

int main(void)
{

    short a = 2;

    a++;
    printf("%p\n", &a);
    printf("%p\n", &a);

    short *p;

    p = &a;

    printf("%p\n", p);
    printf("%p\n", &a);

    *p = 3;

    printf("%d\n", a);

    (*p)++;

    printf("p: %d\n", p);
    printf("*p: %p\n", *p);
    printf("a: %d\n", a);
    printf("&a: %p\n", &a);

    printf("-----------------------------------\n\n");

    short *A[4] = {1, 2, 3, 4};

    printf("%d\n", (*A)++);
    printf("%d\n", A[0]++);

    A[0] = 1;

    printf("%d\n", (*(A + 1))++);
    printf("%d\n", A[1]++);

    A[1] = 2;

    printf("%d\n", &A[1] == A + 1 ? 1 : 0);
    printf("%p\n", &A[1]);
    printf("%p\n", A + 1);

    // *A[1] = 7;

    printf("%p\n", A[0]);
    printf("%p\n", *A[1]);
}