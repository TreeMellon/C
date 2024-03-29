#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }

    int *B = realloc(A, 2 * n * sizeof(int));
    printf("Prev block address = %d, new address = %d\n", A, B);
    // free(A);
    // A = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
    }

    return 0;
}