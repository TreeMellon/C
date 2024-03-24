#include <stdio.h>

int func(int a)
{
    a = 200;
    printf("func called a = %d", a);
}

int main()
{
    int x = 10;
    func(x);
}