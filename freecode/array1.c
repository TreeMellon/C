#include <stdio.h>

int main()
{
    int A[] = {2, 4, 5, 8, 1};
    printf("%d\n", A);
    printf("%d\n", &A[0]);
    printf("%d\n", A[0]);
    printf("%d\n", *A);

    printf("sizeof array %d\n", sizeof(A) / sizeof(*A));

    int i, n;
    n = sizeof(A) / sizeof(*A);
    for (i = 0; i < n; i++)
    {
        printf("%d\n", A);
        printf("%d\n", &A[i]);
        printf("%d\n", A[i]);
        printf("%d\n", *A);
    }
}