#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;

void Insert(int data, int n)
{
    Node *temp1 = malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1)
    {
        temp1->next = head;
        head = temp1;

        return;
    }
}

void Print();

main()
{

    head = NULL;
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print();

    exit(0);
}