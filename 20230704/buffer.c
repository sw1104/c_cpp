#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// int main(void)
// {
//     int a;
//     char c;

//     scanf("%d", &a);
//     printf("%d\n", a);

//     scanf("%c", &c);
//     printf("%c\n", c);

//     return 0;
// }

// 컴퓨터는 줄바꿈이나 공백 등도 아스키코드로 관리하기 때문에
// a에 숫자를 입력 후
// 엔터를 칠 경우
// c가 줄바꿈을 받아들이게 되서
// 끝나버린다.
// 이는 입력 버퍼의 오류이다.
// 아래는 강의에서 알려준 코드인데 돌아가지 않음..

int main(void)
{
    int a;
    char c;
    scanf("%d", &a);
    printf("%d\n", a);
    int temp; // 모든 문자열은 내부적으로 숫자로 관리하기 때문에 숫자형으로 받을 수 있다.
    // 한 자씩 받아서 파일의 끝이거나 개행 문자를 만나면 입력을 멈추므로 항상 입력 버퍼를 비워준다.
    while ((temp = getchar()) != EOF && temp != '\n')
    {
    }
    // EOF는 파일의 끝
    scanf("%c", &c);
    printf("%c\n", c);

    return 0;
}

// GPT에게 물어본 결과

// int main(void)
// {
//     int a;
//     char c;

//     scanf("%d", &a);
//     printf("%d\n", a);

//     scanf(" "); // scanf를 이용해서 입력 버퍼 비우기

//     scanf("%c", &c);
//     printf("%c\n", c);

//     return 0;
// }