#include <stdio.h>

int main(void)
{
    int arr[4];

    // for (int i = 0; i < 4; i++)
    // {
    //     arr[i] = 0;
    // }

    for (short *p = &arr; p < arr + 4; p++)
    {
        *p = 0;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
}