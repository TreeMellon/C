#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void Enqueue(int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    Node *temp = front;
    if (front == NULL)
        return;

    if (front == rear)
    {
        front = rear = NULL;
    }

    else
    {
        front = front->next;
    }
    free(temp);
}

void Print()
{
    Node *temp = front;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Top()
{
    printf("%d\n", front->data);
}

void Rear()
{
    printf("%d\n", rear->data);
}

int main()
{
    Enqueue(3);
    Print();
    Enqueue(20);
    Print();
    Dequeue();
    Print();
    Top();
    Enqueue(200);
    Print();
    Rear();
}