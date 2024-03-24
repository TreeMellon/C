#include <stdio.h>

int main()
{

    int array[100], pos, c, size, value;
    printf("Enter the size of array:");
    scanf("%d", &size);
    printf("\n Enter %d elements in array: \n ", size);
    for (c = 0; c < size; c++)
    {
        scanf("%d", &array[c]);
    }

    printf("Enter the location where you wish to insert an item \n");
    scanf("%d", &pos);

    printf("Enter the value to insert \n");

    scanf("%d", &value);

    for (c = size - 1; c >= pos - 1; c--)
    {
        array[c + 1] = array[c];
    }

    array[pos - 1] = value;

    for (c = 0; c <= size; c++)
    {
        printf("%d\n", array[c]);
    }

    // getch();
    exit(0);
}