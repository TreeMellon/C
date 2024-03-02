#include <stdio.h>

int main()
{
    int a;
    int *p;
    a = 10;
    p = &a;

    printf("%d\n", p);
    printf("a = %d\n", a);

    *p = 12;
    //   printf("%d\n", *p);
    //   printf("%d\n", &a);
    printf("a = %d\n", a);

    int b = 20;
    *p = b;
    printf("Address of P is %d\n", p);
    printf("Value at P is %d\n", *p);
}