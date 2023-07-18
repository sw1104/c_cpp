#include <stdio.h>

int main()
{
    typedef unsigned int unit32;
    typedef unsigned short unit16;
    typedef unsigned char unit8;

    typedef struct
    {
        char *name;
        int cost;
    } Menu;

    Menu a;
    a.name = "bugger";
    a.cost = 10000;

    printf("name: %s\n", a.name);
    printf("const: %d\n", a.cost);

    Menu *p = &a;
    p->name = "pizza";
    p->cost = 13000;

    printf("name: %s\n", a.name);
    printf("const: %d\n", a.cost);

    return 0;
}

void str_append(char *str, char *str2)
{
}

char *str_find(char *str, char *str2)
{
}

void str_trim(char *str)
{
}

int str_to_int(char *str)
{
}
