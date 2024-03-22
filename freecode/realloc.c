#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    // int *A = (int *)malloc(n * sizeof(int));
    int *A = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }

    //  int *B = (int *)realloc(A, 2 * n * sizeof(int));

    // int *B = (int *)realloc(A, (1 / 2) * n * sizeof(int));

    int *B = (int *)realloc(NULL, n * sizeof(int));

    printf("Prev block address = %d, new address = %d\n", A, B);

    //   for (int i = 0; i < 2 * n; i++)
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", B[i]);
    }
}