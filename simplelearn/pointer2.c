#include <stdio.h>

int main()
{
    // int var, *ptr1, **ptr2;
    // var = 5;
    // ptr1 = &var;
    // ptr2 = &ptr1;

    // printf("*prt1 = %d\n, *ptr2 = %d\n", *ptr1, **ptr2);

    int a[3] = {2, 3, 5};
    int *ptr[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = &a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        printf("*ptr[i] = %d\n", *ptr[i]);
    }
}