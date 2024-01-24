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
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
}
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    postOrder(root->left);
    postOrder(root->right);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("InOrder: ");
    inOrder(root);
    printf("\nPreOrder: ");
    preOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
    return 0;
}