#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;

void Reverse(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }

    Reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void ReversePrint(Node *head)
{
    if (head == NULL)
        return;
    ReversePrint(head->next);
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
    head = NULL;

    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);

    ReversePrint(head);

    Reverse(head);

    ReversePrint(head);

    //   head = Reverse(head, 2);

    exit(0);
}