#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    printf("%d", sizeof("llow"));

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *my_string, const char *overwrite_string, int s)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // 문자열 길이 계산
    int my_string_length = strlen(my_string);
    int overwrite_string_length = strlen(overwrite_string);

    // 결과 문자열을 저장할 동적 할당 메모리 생성
    char *answer = (char *)malloc((my_string_length + 1) * sizeof(char));
    strcpy(answer, my_string);

    // 문자열 일부 교체
    strncpy(answer + s, overwrite_string, overwrite_string_length);

    return answer;
}