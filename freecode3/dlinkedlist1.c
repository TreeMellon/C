#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev
} Node;

Node *head;

Node *GetNewNode(int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    else
    {
        Node *lastNode = head;

        // last node's next address will be NULL.
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        // add the newNode at the end of the linked list
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode = head;
    }
}

void Print()
{
    Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    Node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    InsertAtHead(1);
    Print();
    ReversePrint();

    InsertAtHead(2);
    Print();
    ReversePrint();

    InsertAtHead(3);
    Print();
    ReversePrint();

    InsertAtTail(300);
    Print();
    ReversePrint();

    exit(0);
}
