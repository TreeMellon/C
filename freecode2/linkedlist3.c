#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;

void Insert(int val)
{
    // create a new node
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    // if head is NULL, it is an empty list
    if (head == NULL)
        head = newNode;
    // Otherwise, find the last node and add the newNode
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
    }
}

void Print(Node *head)
{
    //   struct Node *temp = head;
    while (head != NULL)
    {
        printf(" %d \n", head->data);
        head = head->next;
    }

    // printf("print");
}

void Delete(int n)
{

    //  Node *temp1 = malloc(sizeof(Node));
    Node *temp1 = head;

    if (n == 1)
    {

        head = temp1->next;
        free(temp1);
        return;
    }

    int i;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    //  Node *temp2 = malloc(sizeof(Node));
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int main()
{

    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);

    Print(head);

    int n;
    printf("Enter a position %d\n", n);
    scanf("%d", &n);
    Delete(n);
    Print(head);

    exit(0);
}