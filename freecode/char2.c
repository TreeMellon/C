#include <stdio.h>

int main()
{
    char C[20] = "JOHN";
    printf("Size = %d\n", sizeof(C));
    int len = strlen(C);
    printf("Length = %d\n", len);
}