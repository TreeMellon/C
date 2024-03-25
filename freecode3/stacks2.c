#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void Push(int x)
{

    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    Node *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->next;
    free(temp);
}

int main()
{
}