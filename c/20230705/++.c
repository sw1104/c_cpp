#include <stdio.h>

int main()
{
    // char a;
    // unsigned char b;

    // a = -35;
    // b = -35;

    // printf("%c 0x%x\n", a, a);
    // printf("%c 0x%x\n", b, b);
    // printf("\n");
    // printf("a=%d, b=%d\n", a, b);

    // return 0;
    // case 1
    int a = 0;
    printf("case1 : %d\n", ++a);

    // case 2
    a = 0;
    printf("case2 : %d\n", a++);

    // case 3
    a = 0;
    printf("case3 : %d %d\n", ++a, a);

    // case 4
    a = 0;
    printf("case4 : %d %d\n", a++, a);

    // case 5
    a = 0;
    printf("case5 : %d %d %d\n", a, a++, a);

    // case 6
    a = 0;
    printf("case6 : %d %d\n", a, a++);

    a = 0;
    printf("case7 : %d %d %d %d %d\n", ++a, ++a, ++a, ++a, ++a);

    short A[4] = {1, 2, 3, 4};

    printf("%p\n", &A);
    printf("%p\n", A);
    printf("%d\n", A[0]);
    printf("%p\n", A + 1);
    printf("%d\n", A[1]);
    printf("%p\n", A + 2);
    printf("%d\n", A[2]);
    printf("%p\n", A + 3);
    printf("%d\n", A[3]);
    printf("%p\n", A + 4);
    printf("%d\n", A[4]);
    printf("%p\n", A + 5);
    printf("%d\n", A[5]);
}