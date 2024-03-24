#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Print(Node *head)
{
    if (head == NULL)
        return;
    Print(head->next);
    printf("%d \n ", head->data);

    // while (head != NULL)
    // {
    //     printf(" %d \n", head->data);
    //     head = head->next;
    // }
}

Node *Insert(Node *head, int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

int main()
{
    Node *head = NULL;

    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);

    Print(head);

    exit(0);
}