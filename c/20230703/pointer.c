#include <stdio.h>

// int main(void)
// {
//     int i = 100;
//     int *ia = &i;

//     printf("i의 값은 %d이며, 크기는 %d이고, 주소 값은 %#x 이다. \n", i, sizeof(ia), ia);
//     printf("주소에 저장된 값은 %d. \n", *ia);

//     return 0;
// }

int main(void)
{
    char *ptr_char = 0;
    int *ptr_int = NULL;
    double *ptr_double = 0x00;

    printf("ptr_char: %#x \n", ptr_char);
    printf("ptr_int: %#x \n", ptr_int);
    printf("ptr_double: %#x \n", ptr_double);
    printf("ptr_char +1: %#x \n", ++ptr_char);
    printf("ptr_int +1: %#x \n", ++ptr_int);
    printf("ptr_double +1: %#x \n", ++ptr_double);
}