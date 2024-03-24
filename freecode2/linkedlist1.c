#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// struct Node *head;

void *Insert(Node **head, int x)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (*head != NULL)
        temp->next = *head;
    *head = temp;

    // if (head != NULL)
    //     temp->next = head;
    // head = temp;
    //  return head;
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

main()
{
    Node *head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        //     head = Insert(head, x);
        Insert(&head, x);
        Print(head);
    }

    exit(0);
}