#include <stdio.h>

int main()
{

    int first[3][3] = {3, 5, 1, 20, 25, 90, 203, 402, 154};
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            printf("%d\n", first[i][j]);
        }
}