#include <stdio.h>
int main()
{
    int a = 1025;
    int *p;
    p = &a;
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value= %d\n bytes\n", p, *p);

    void *p0;
    p0 = p;

    // printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d", p0);
}