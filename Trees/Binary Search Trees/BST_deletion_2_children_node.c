#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *predecessor(struct node *ptr)
{
    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

struct node *successor(struct node *ptr)
{
    while (ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

// ---------------INSERT OPERATION---------------------//
void insert()
{
    struct node *ptr;
    struct node *parent = root;

    ptr = (struct node *)malloc(sizeof(struct node));

    int key;
    printf("Enter the data to be inserted: ");
    scanf("%d", &key);
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;

    if (root == NULL)
        root = ptr;
    else
    {
        struct node *curr = root;
        while (curr)
        {
            parent = curr;
            if (ptr->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if (ptr->data < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;
    }
}
// ---------------------DELETION OPERATION-----------------------//
void delete (int key)
{
    if (root == NULL)
        printf("Null tree");
    else
    {
        struct node *curr, *parent;
        curr = parent = root;

        while (curr->data != key)
        {
            parent = curr;
            if (key > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        struct node *temp = predecessor(curr->left);
        // printf("predecessor: %d\n",temp->data);
        // printf("successor: %d\n\n",successor(curr->right));

        curr->data = temp->data;
        if (curr->left == temp)
        {
            curr->left = NULL;
            free(temp);
        }
        else
        {
            struct node *a = curr;
            a = a->left;

            while (a->right != temp)
                a = a->right;

            a->right = NULL;
            free(temp);
        }
    }
}
void inOrder(struct node *pt)
{
    struct node *ptr = pt;
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        printf("%d ", ptr->data);
        inOrder(ptr->right);
    }
}
int main()
{
    int n;
    printf("number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    printf("\nInorder Traversal of tree: ");
    inOrder(root);
    printf("\n");

    // printf("predecessor: %d",predecessor(root->left));
    // printf("successor: %d",successor(root->right));
    int key;
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);
    delete (key);
    
    printf("\nInorder Traversal of tree: ");
    inOrder(root);
    return 0;
}
