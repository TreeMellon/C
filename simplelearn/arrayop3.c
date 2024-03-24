#include <stdio.h>

int main()
{
    int n, i, array[10];
    printf("enter the size of an array");
    scanf("%d", &n);
    printf("enter elements in an array");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    n--;

    for (i = 0; i < n; i++)
    {
        array[i] = array[i + 1];
    }

    printf("\n after deleteion");

    for (i = 0; i < n; i++)
        printf("\n%d", array[i]);

    // getch();
}