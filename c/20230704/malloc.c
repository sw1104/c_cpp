#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(sizeof(int));
    printf("%d\n", a);
    free(a);
    a = malloc(sizeof(int));
    printf("%d\n", a);
    free(a);

    a = malloc(sizeof(int));
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);
    printf("%d\n", a);
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);

    a = malloc(sizeof(int));
    printf("%d\n", a);
    free(a);
    printf("%d\n", a);
    printf("%d\n", a);
    printf("%d\n", a);
    printf("%d\n", a);

    return 0;
}