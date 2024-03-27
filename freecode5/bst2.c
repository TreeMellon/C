#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

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
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
    }
}

int main()
{
}