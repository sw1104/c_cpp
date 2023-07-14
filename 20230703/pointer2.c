#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;

    if (ptr_a != ptr_b)
    {
        printf("ptr_a value = %d \n", *ptr_a);
        printf("ptr_b value = %d \n", *ptr_b);
        printf("ptr_a != ptr_b \n\n");
        ptr_b = ptr_a;
    }

    printf("ptr_a value = %d \n", *ptr_a);
    printf("ptr_b value = %d \n", *ptr_b);

    if (ptr_a == ptr_b)
    {
        printf("ptr_a = ptr_b \n");
        ptr_a = 15;
        ptr_b = 7;
    }

    if (ptr_a != ptr_b)
    {
        printf("ptr_a");
    }
}