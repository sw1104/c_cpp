#include <stdio.h>

void local(int);

int main(void)
{
    int var = 10;

    printf("var value : %d \n", var);

    local(var);
    printf("local() var value : %d \n", var);

    return 0;
}

void local(int num)
{
    num += 50;
}