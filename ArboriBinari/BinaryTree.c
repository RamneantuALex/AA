#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *right, *left;
};
struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node *insert(struct Node *node, int value)
{
    if (node == NULL)
    {
        return newNode(value);
    }
    if (value < node->key)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->key)
    {
        node->right = insert(node->right, value);
    }
    return node;
}
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrder(root);
    return 0;
}