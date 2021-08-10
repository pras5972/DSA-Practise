#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert()
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}
int len()
{
    int count = 0;

    if (head != NULL)
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}
void show()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Nothing to print");
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int del_mid()
{
    struct node *temp = head;
    struct node *p= head;
    int length = len();
    int mid = 0;

    while (mid != length / 2)
    {
        temp = temp->next;
        mid++;
    }
    while (p->next != temp)
    {
        p=p->next;
    }
    
    p->next=temp->next;
    temp->next = NULL;
    free(temp);
    
}
int main()
{
    while (1)
    {
        printf("\n1 for inserting\n");
        printf("2 for deleting mid\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insert();
                break;
        case 2: del_mid();
                show();
                break;
        
        default:
            printf("wrong");
            break;
        }
    }
    return 0;
}
