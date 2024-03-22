#include <stdio.h>

void print(char *C)
{
    C[0] = 'A';
    int i = 0;
    // while (C[i] != '\0')
    while (*C != '\0')
    {
        printf("%c", C[i]);
        C++;
        //  i++;
    }
    printf("\n");
}

int main()
{
    char C[20] = "Hello";
    // char *C = "Hello";
    print(C);
}