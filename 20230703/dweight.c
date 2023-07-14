#include <stdio.h>

int main(void)
{
    int height;
    int length;
    int width;
    int volume;
    int weigth;

    height = 8;
    length = 12;
    width = 10;

    volume = height * length * width;
    weigth = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volumne (cubic inches): %d\n", volume);
    printf("Volumne 2: %d\n", length * width * height);
    printf("Dimensional weigth (pounds) : %d\n", weigth);

    return 0;
}