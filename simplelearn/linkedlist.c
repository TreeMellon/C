#include <stdio.h>

typedef struct Node
{

    int x;
    struct Node *next;
} Node;

int main()
{
    Node root, elem2;
    root.x = 15;
    root.next = malloc(sizeof(Node));

    root.next->x = -2;
    // root.next->next = NULL;

    root.next->next = malloc(sizeof(Node));
    root.next->next->x = 22;
    root.next->next->next = NULL;

    // printf("First : %d\n", root.x);
    // printf("Second : %d\n", root.next->x);

    Node *curr = &root;
    while (curr != NULL)
    {
        printf("First : %d\n", curr->x);
        printf("First : %d\n", curr->next);
        curr = curr->next;
    }

    for (Node *curr = &root; curr != NULL; curr = curr->next)
    {
        printf("First : %d\n", curr->x);
        printf("First : %d\n", curr->next);
    }

    free(root.next->next);
    free(root.next);

    return 0;
}