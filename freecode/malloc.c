#include <stdio.h>

int main()
{
    int a;
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = (int *)malloc(20 * sizeof(int));

    p[1] = 100;
    p[2] = 1000;

    int i;
    for (i = 0; i < 20; i++)
    {
        printf("p[i] is %d\n", p[i]);
    }

      // 확실하지 않음
    free(*(p));

    printf("p[1] is %d\n", p[1]);

    return 0;
}