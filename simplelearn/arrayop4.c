#include <stdio.h>

int main()
{
    int i, j, temp, size, array[100];
    printf("Enter the size \n");
    scanf("%d", &size);
    printf("Enter the numbers \n");

    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);

    for (i = 0; i < size; i++)
        for (j = i + 1; j < size; j++)
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

    printf("The numbers arrange in ascending");
    for (i = 0; i < size; i++)
        printf("array array[i] = %d\n", array[i]);
}