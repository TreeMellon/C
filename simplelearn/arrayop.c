#include <stdio.h>

int main()
{
    // int a[5] = {1, 2, 3, 4, 5};
    // int i;
    // for (i = 0; i < 5; i++)
    // {
    //     printf("a[i] = %d\n", a[i]);
    // }
    int array[10], n, i, item;
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("\n Enter Elements in array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        printf("n is %d", n);
    }

    printf("\n enter the element at the beginning");
    scanf("%d", &item);

    n++;

    for (i = n; i > 1; i--)
    {
        array[i - 1] = array[i - 2];
    }

    array[0] = item;

    for (i = 0; i < n; i++)
    {
        printf("\n%d", array[i]);
    }

    getch();
}