#include <stdio.h>

void PrintHello(char *name)
{
    printf("Hello %s\n");
}
int Add(int a, int b)
{
    return a + b;
}
int main()
{
    void (*ptr)(char *);
    ptr = PrintHello;
    ptr("Tom");
}