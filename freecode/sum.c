#include <stdio.h>

// int SumOfElements(int A[])
// {
//     int i, sum = 0;
//     int size = sizeof(A) / sizeof(A[0]);
//     printf("SOA = %d size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

//     for (i = 0; i < size; i++)
//     {
//         sum += A[i];
//     }
//     return sum;
// }

int SumOfElements(int *A, int size)
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += A[i];
    }
    return sum;
}

int main()
{
    int A[] = {2, 4, 5, 8, 1};
    int size = sizeof(A) / sizeof(A[0]);

    printf("SOA = %d size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    // int total = SumOfElements(A);

    int total = SumOfElements(A, size);

    printf("SUM is %d\n", total);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", &A[i]);
    //     printf("%d\n", A + i);
    //     printf("%d\n", A[i]);
    //     printf("%d\n", *(A + i));
    // }
}