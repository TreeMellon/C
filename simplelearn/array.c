#include <stdio.h>

int main()
{
    // int arr[3] = {2, 3, 5};
    // int *tr;
    // tr = &arr[0];
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("*tr %d\n", *tr);
    //     tr++;
    // }

    // int arr[3] = {2, 3, 5};
    // int *tr;
    // tr = &arr[2];
    // for (int i = 3; i > 0; i--)
    // {
    //     printf("*tr %d\n", *tr);
    //     tr--;
    // }
    // printf("end");

    // int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    // int *ptr;
    // ptr = &arr[0];
    // int n = 2;
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("*ptr = %d\n", *ptr);
    //     ptr = ptr + n;
    // }

    int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    int *ptr;
    ptr = &arr[6];
    int n = 2;
    for (int i = 0; i < 7; i++)
    {
        printf("*ptr = %d\n", *ptr);
        ptr = ptr - n;
    }
}