#include <stdio.h>

int func(int *a)
{
    *a = 200;
    printf("func called a = %d", a);

    // return a;
}

int main()
{
    int x = 100;
    printf("&x is %d\n", &x);
    func(&x);
    printf("func called x = %d", x);
}
