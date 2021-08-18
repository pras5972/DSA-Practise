#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = data;

    return ptr;
}
struct node *search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;

        else if (key > root->data)
            root = root->right;

        else
            root = root->left;
    }

    return NULL;
}

int main()
{
    struct node *root = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    int key;
    printf("Key to be searched: ");
    scanf("%d", &key);

    struct node *n = search(root, key);
    if (n != NULL)
        printf("FOUND");
    else
        printf("NO");
    return 0;
}