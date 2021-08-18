#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;


// ---------------INSERT OPERATION---------------------
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

void delete(int key)
{
    if(root == NULL)
        printf("Null tree");
    else{
        struct node *curr, *parent;
        curr = parent = root;

        while (curr->data != key)
        {
            parent=curr;
            if(key > curr->data)
                curr = curr->right;
            else    
                curr = curr->left;
        }

        if(curr == parent->right)
        {
            if(curr->left == NULL)
            {
                parent->right = curr->right;
                curr->right = NULL;    
                free(curr);
            }
            else{
                parent->right = curr->left;
                curr->left = NULL;
                free(curr);
            }
        }
        else
        {
            if(curr->left == NULL){
                parent->left = curr->right;
                curr->right = NULL;    
                free(curr);
            }
            else{
                parent->left = curr->left;
                curr->left = NULL;
                free(curr);
            }
        }
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
    inOrder(root);
    printf("\n");
    
    int key;
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);
    delete(key);

    inOrder(root);
    return 0;
}