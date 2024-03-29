#include <stdio.h>
#include <stdlib.h>

void display(char **output)
{
    printf("%s\n", *output);
    *output = "this is another test";
}

int main()
{
    char *str = "This is a test";
    display(&str);
    printf("after the call %s\n", str);
    return 0;
}