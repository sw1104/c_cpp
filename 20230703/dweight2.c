#include <stdio.h>
#define INCHES_PER_POUND (166)

int main(void)
{
    int height;
    int length;
    int width;
    int volume;
    int weight;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);

    printf("%d\n", height);
    printf("%d\n", length);
    printf("%d\n", width);

    volume = height * length * width;
    // weight = (volume + 165) / 166;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);
    // printf("Dimensional weight2 (pounds): %d\n", weight2);

    return 0;
}