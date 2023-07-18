#include <stdio.h>

int main(void)

{

    char ch;

    printf("EOF가 입력될 때까지 영문자를 계속 입력받습니다 :\n");

    printf("(윈도우에서 EOF의 강제 발생은 Ctrl+Z를 누르고 나서 Enter를 누르면 됩니다)\n");

    while ((ch = getchar()) != EOF)

    {

        putchar(ch);
    }

    return 0;
}