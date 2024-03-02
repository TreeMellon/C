#include <stdio.h>

void Increment(int a)
{
    a = a + 1;
    printf("Address of variable a in increment = %d\n", &a);
}

int main()
{
    int a;
    a = 10;
    Increment(a);
    //   printf("a = %d",a);
    printf("Address of variable a in increment = %d\n", &a);
}
