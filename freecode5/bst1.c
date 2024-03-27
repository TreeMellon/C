#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int FindMin(BstNode *root)
{
    if (root == NULL)
    {
        printf("value is empty");
        return -1;
    }
    //    BstNode *current = root;
    else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
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

    int min, height;
    min = FindMin(root);
    printf("min data is %d\n", min);

    height = FindHeight(root);
    printf("height is %d\n", height);

    int number;

    printf("Type number to search");
    scanf("%d", &number);

    if (Search(root, number) == true)
    {
        printf("number found");
    }
    else
    {
        printf("number not found");
    }

    return 0;
}