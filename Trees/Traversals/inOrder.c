#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right=NULL;     
    ptr->data = data ;

    return ptr;
}
void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main()
{
    // struct node *root=createNode(4);
    // struct node *p1=createNode(1);
    // struct node *p2=createNode(6);
    // struct node *p3=createNode(5);
    // struct node *p4=createNode(2);
        struct node *root=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(root);
    
    
    return 0;
}