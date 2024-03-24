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

    printf("A: %d\n", A.x);

    A.next->x = 22;
    A.next->next = NULL;

    Node *curr = &A;

    printf("curr: %p\n", curr);
    printf("*curr: %p\n", *curr);
    printf("*curr: %p\n", &A);
    // printf("*curr: %d\n", **curr);

    while (curr != NULL)
    {
        printf("curr x value: %d\n", curr->x);
        curr = curr->next;
    }

    // seperate example

    Node *B = NULL;
    printf("&B: %p\n", &B);

    Node *temp = malloc(sizeof(struct Node));
    temp->x = 1000;
    temp->next = NULL;

    printf("temp->x %d\n", temp->x);
    printf("temp->x %d\n", &(temp->x));

    printf("temp->next %d\n", (temp->next));
    printf("temp->next %p\n", (temp->next));
    printf("&(temp->next) %d\n", &(temp->next));
    printf("&(temp->next) %p\n", &(temp->next));

    B = temp;

    printf("&B %p\n", &B);
    printf("B %d\n", B);
    printf("(*B).x %d\n", (*B).x);
    printf("(*B).next %p\n", (*B).next);

    Node *C = NULL;
    temp->x = 1100;
    temp->next = NULL;

    C = temp;

    Node *curr2 = B;

    printf("curr2->next %p\n", curr2->next);

    while (curr2->next != NULL)
    {
        curr2 = curr2->next;
        printf("list item &d\n", curr2->x);
    }

    // Node **temp1 = &B;
    // //  temp = &B;

    // printf("**temp1: %d\n", **temp1);

    // (*B).x = 100;
    // printf("(*B).x: %d\n", (*B).x); // print nothing.

    return 0;
}
