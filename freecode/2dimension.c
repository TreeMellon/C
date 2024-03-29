#include <stdio.h>

int main()
{
    int A[2][3] = {{2, 4, 5}, {8, 1, 3}};
    printf("A is %d\n", A);
    printf("*A is %d\n", *A);
    printf("A[0] is %d\n", A[0]);
    printf("&A[0][0] is %d\n", &A[0][0]);

    printf("A[0][1] is %d\n", A[0][1]);
    printf("*(A[0]+1) is %d\n", *(A[0] + 1));
    printf("*(*(A+0)+1) is %d\n", *(*(A + 0) + 1));
}