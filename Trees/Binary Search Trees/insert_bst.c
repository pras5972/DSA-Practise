#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void insert()
{
    struct node *ptr;
    struct node *parent = root;

    ptr = (struct node*)malloc(sizeof(struct node));

    int key;
    printf("Enter the data to be inserted: ");
    scanf("%d",&key);
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;

    if(root == NULL)
        root = ptr;
    else
    {
        struct node *curr = root;
        while(curr)
        {
            parent = curr;
            if(ptr->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if(ptr->data < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;
            

    }
}
void inOrder(struct node *pt)
{
    struct node *ptr = pt;
    if(ptr != NULL)
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        insert();
    }
    printf("\nInorder Traversal of tree: ");
    inOrder(root);
    return 0;
}
