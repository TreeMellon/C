#include <stdio.h>

int main()
{
    int x, y;
    int *p;

    x = 5;
    p = &x;
    y = *p;

    printf("x is %d, y is %d, p is %d, *p is %d\n", x, y, p, *p);
    printf("&x is %d, p is %d\n", &x, p);

    int z;
    int *p1, *p2;

    z = 5;
    p1 = &z;
    p2 = &z;

    *p1 = 2;

    printf("&z is %d, z is %d, *p1 is %d\n", &z, z, *p1);

    *p2 = 6;
    printf("&z is %d, z is %d, p2 is %d\n", &z, z, *p2);
}