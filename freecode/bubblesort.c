#include <stdio.h>

int absolute_compare(int a, int b)
{
    if (abs(a) > abs(b))
        return -1;
    else
        return 1;
}

int compare(int a, int b)
{
    if (a > b)
        return -1;
    else
        return 1;
}

void BubbleSort(int *A, int n, int (*compare)(int, int))
{
    int i, j, temp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
        {
            //         if (A[j] > A[j + 1])
            if (compare(A[j], A[j + 1]) > 0)
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
}

int main()
{
    int i, A[] = {3, 2, 1, 5, 6, 4};
    BubbleSort(A, 6, compare);
    for (i = 0; i < 6; i++)
        printf("%d \n ", A[i]);

    int B[] = {-31, 32, -1, 50, -6, 4};
    BubbleSort(B, 6, absolute_compare);
    for (i = 0; i < 6; i++)
        printf("%d \n ", B[i]);
}