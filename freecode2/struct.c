#include <stdio.h>

typedef struct Node
{
    int x;
    struct Node *next;
} Node;

int main()
{
    Node A;

    A.x = 2;
    A.next = malloc(sizeof(Node));

    A.next->x = 22;
    A.next->next = NULL;

    Node *curr = &A;

    while (curr != NULL)
    {
        printf("curr x value: %d\n", curr->x);
        curr = curr->next;
    }

    return 0;
}
