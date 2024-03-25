#include <stdio.h>

int main()
{
    // int a = 5, *ptr;
    // ptr = &a;
    // printf("a= %d\n", a);
    // printf("*ptr= %d\n", *ptr);

    // int *var;
    // *var = NULL;
    // printf("a= %d\n", *var);

    int *ptr = (int *)malloc(sizeof(int));
    int a = 5;
    ptr = &a;

    //  free(ptr);
    printf("*ptr = %d, ptr = %d\n", *ptr, ptr);

    // 아마도 stack memory 동작방식
    free(ptr);
    printf("after free *ptr = %d, ptr = %d\n", *ptr, ptr);
    printf("&a = %d, a = %d", &a, a);

    return 0;
}
