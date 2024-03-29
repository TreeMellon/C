#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX_Q_SIZE = 500;

int max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

// BstNode *rootPtr;

BstNode *GetNewNode(int value)
{
    BstNode *newNode = malloc(sizeof(BstNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // retrun newly create node address.
    return newNode;
}

BstNode *Insert(BstNode *root, int value)
{
    if (root == NULL)
    {
        root = GetNewNode(value);
        return root;
    }

    else if (value <= root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }

    return root;
}

bool Search(BstNode *root, int value)
{
    if (root == NULL)
        return false;
    else if (root->data == value)
        return true;
    else if (value <= root->data)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}

// int FindMin(BstNode *root)
// {
//     if (root == NULL)
//     {
//         printf("value is empty");
//         return -1;
//     }
//     //    BstNode *current = root;
//     while (root->left != NULL)
//     {
//         root = root->left;
//     }
//     //  printf("min value is %d\n", current->data);
//     return root->data;
// }

BstNode *FindMin(BstNode *root)
{
    if (root == NULL)
    {
        printf("value is empty");
        return NULL;
    }
    //    BstNode *current = root;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

void enQueue(struct node **queue, int *rear,
             struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

struct node **createQueue(int *front, int *rear)
{
    BstNode **queue = malloc(
        sizeof(BstNode) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void printLevelOrder(struct node *root)
{
    // if (root == NULL)
    //     return;
    int rear, front;
    BstNode **queue = createQueue(&front, &rear);
    BstNode *temp_node = root;

    while (temp_node)
    {
        printf("%d ", temp_node->data);

        // Enqueue left child
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        // Enqueue right child
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        // Dequeue node and make it temp_node
        temp_node = deQueue(queue, &front);
    }
}

void Preorder(BstNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(BstNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Preorder(root->right);
}

void Postorder(BstNode *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

bool IsSubtreeLesser(BstNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(BstNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

// bool IsBinarySearchTree(BstNode *root)
// {
//     if (root == NULL)
//         return true;
//     if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
//     {
//         printf("return true\n");
//         return true;
//     }

//     printf("return false\n");
//     return false;
// }

bool IsBinarySearchTree(BstNode *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->data > minValue && root->data < maxValue && IsBinarySearchTree(root->left, minValue, root->data) && IsBinarySearchTree(root->right, root->data, maxValue))
    {
        printf("return true\n");
        return true;
    }

    printf("return false\n");
    return false;
}

BstNode *Delete(BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

BstNode *Getsuccessor(BstNode *root, int data)
{
    BstNode *current = Find(root, data);
    if (current == NULL)
        return NULL;
    if (current->right != NULL)
    {
        return FindMin(current->right);
    }

    else
    {
        BstNode *successor = NULL;
        BstNode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

int main()
{

    BstNode *root = NULL;
    root = Insert(root, 15);
    printf("root value is %d\n", root->data);
    root = Insert(root, 10);
    printf("root left node value is %d\n", root->left->data);
    root = Insert(root, 20);
    printf("root right node value is %d\n", root->right->data);
    root = Insert(root, 13);
    root = Insert(root, 25);
    root = Insert(root, 30);

    int min, height;
    min = FindMin(root);
    printf("min data is %d\n", min);

    height = FindHeight(root);
    printf("height is %d\n", height);

    printLevelOrder(root);

    int number;

    printf("Type number to search");
    scanf("%d", &number);

    if (Search(root, number) == true)
    {
        printf("number found\n");
    }
    else
    {
        printf("number not found\n");
    }

    Delete(root, 30);

    printLevelOrder(root);

    //  Preorder(root);
    // Inorder(root);
    // Postorder(root);
    // bool test;
    // test = IsBinarySearchTree(root);
    // printf("binary tree test result is %d\n", test);

    return 0;
}