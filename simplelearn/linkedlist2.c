// #define _CRTDBG_MAP_ALLOC
// #include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
} Node;

void insert_end(Node **root, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void insert_beginning(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_after(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->x = value;
    new_node->next = node->next;
    node->next = new_node;
}

void insert_sorted(Node **root, int value)
{
    if (*root == NULL || (**root).x >= value)
    {
        insert_beginning(root, value);
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->x >= value)
        {
            insert_after(curr, value);
            break;
        }
        curr = curr->next;
    }

    insert_after(curr, value);
}

void remove_element(Node **root, int value)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->x == value)
    {
        Node *to_remove = *root;
        *root = (*root)->next;
        free(to_remove);

        return;
    }

    for (Node *curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->x == value)
        {
            Node *to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
        }
    }
}

void deallocate(Node **root)
{
    Node *curr = *root;
    while (curr != NULL)
    {
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void reverse(Node **root)
{
    Node *prev = NULL;
    Node *curr = *root;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *root = prev;
}

int has_loops(Node *root)
{
    Node *slow = root;
    Node *fast = root;

    while (slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int count(Node *root)
{
    int c = 0;
    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        c++;
    }
    return c;
}

int count_recursive(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + count(node->next);
}

int main()
{
    Node *root = NULL;
    // Node *root = malloc(sizeof(Node));
    // if (root == NULL)
    // {
    //     exit(2);
    // }
    // root->x = 15;
    // root->next = NULL;

    // printf("First : %d\n", root.x);
    // printf("Second : %d\n", root.next->x);

    // insert_end(&root, 3);
    // insert_end(&root, 11);

    // insert_beginning(&root, 13);
    // insert_beginning(&root, 100);

    // insert_after(root->next->next, 7);
    // insert_after(root->next->next->next, 9000);

    // insert_sorted(&root, 300);
    // insert_sorted(&root, 30);
    // insert_sorted(&root, 3);
    // insert_sorted(&root, 900);

    // //  remove_element(&root, 3);

    // reverse(&root);

    insert_end(&root, 3);
    insert_end(&root, 11);
    insert_end(&root, 200);
    insert_end(&root, 900);

    // root->next->next->next->next = root->next;

    // if (has_loops(root) == 1)
    // {
    //     printf("Linked list has a loop");

    //     return 1;
    // }

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("First : %d\n", curr->x);
        printf("First : %d\n", curr->next);
    }

    int p = 0;
    p = count_recursive(root);

    printf("Linked list has %d elements\n", p);

    deallocate(&root);

    // _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    // _CrtDumpMemoryLeaks();

    return 0;
}