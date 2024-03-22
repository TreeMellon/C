#include <stdio.h>

void Double(int *A, int size)
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
    {
        A[i] = A[i] * 2;
    }
}

int main()
{
    int A[] = {2, 4, 5, 8, 1};
    int size = sizeof(A) / sizeof(A[0]);
    int i;
    Double(A, size);
    for (i = 0; i < size; i++)
    {
        printf("array value is %d\n", A[i]);
    }
}