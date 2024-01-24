#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int cheie;
    struct Node *right, *left;
};

struct Node *newNode(int key)
{
    struct Node *nod = (struct Node *)malloc(sizeof(struct Node));
    nod->left = NULL;
    nod->right = NULL;
    nod->cheie = key;
    return nod;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->cheie)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->cheie)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inOrder(struct Node *nod)
{
    if (nod != NULL)
    {
        inOrder(nod->left);
        printf("%d ", nod->cheie);
        inOrder(nod->right);
    }
}
struct Node *Minim(struct Node *nod)
{
    if (nod->left != NULL)
        return Minim(nod->left);
    return nod;
}
struct Node *Delete(struct Node *nod, int val)
{
    if (nod == NULL)
        return nod;
    else if (val < nod->cheie)
    {
        nod->left = Delete(nod->left, val);
    }
    else if (val > nod->cheie)
    {
        nod->right = Delete(nod->right, val);
    }
    else
    {
        // Case 1: Fara copil pur si simplu stergem nodul
        if (nod->left == NULL && nod->right == NULL)
        {
            free(nod);
            nod = NULL;
        }
        // Case 2:Avem un copil dreapta
        else if (nod->left == NULL)
        {
            struct Node *temp = nod;
            nod = nod->right;
            free(temp);
        }
        // Case 2.1 Avem copil la stanga
        else if (nod->right == NULL)
        {
            struct Node *temp = nod;
            nod = nod->left;
            free(temp);
        }
        // Case 3: 2 child
        else
        {
            struct Node *temp = Minim(nod->right);
            nod->cheie = temp->cheie;
            nod->right = Delete(nod->right, temp->cheie);
        }
    }
    return nod;
}

struct Node *deleteEven(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    root->left = deleteEven(root->left);
    root->right = deleteEven(root->right);

    if (root->cheie % 2 == 0)
    {
        root = Delete(root, root->cheie);
    }

    return root;
}
int Height(struct Node *nod)
{
    if (nod == NULL)
        return 0;
    if (Height(nod->left) > Height(nod->right))
        return 1 + Height(nod->left);
    else
        return 1 + Height(nod->right);
}
int isAVL(struct Node *nod)
{
    if (nod == NULL)
        return 0;
    int left = Height(nod->left);
    int right = Height(nod->right);
    if (abs(left - right) <= 1 && isAVL(nod->left) && isAVL(nod->right))
        return 1;
    return 0;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 12);
    insert(root, -7);
    insert(root, 45);
    insert(root, 32);
    insert(root, 2);
    insert(root, 22);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 9);
    insert(root, 90);
    insert(root, 89);
    insert(root, 225);
    insert(root, 0);
    isAVL(root);
    if (isAVL(root))
    {
        printf("Arborele este echilibrat AVL\n");
    }
    else
        printf("Arborele nu este echilibrat AVL\n");
    root = deleteEven(root);
    inOrder(root);
    return 0;
}