#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int A = *((int *)a);
    int B = *((int *)b);

    return abs(A) - abs(B);
}

int main()
{
    int i = 0;
    int B[] = {-31, 32, -1, 50, -6, 4};
    qsort(B, 6, sizeof(int), compare);
    for (i = 0; i < 6; i++)
        printf("%d \n ", B[i]);
}