#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
struct Node* append(struct node *t,int val)
{
    struct node *new=createnode(val);
    struct node *temp=t;
    if(temp==NULL)
    {
        t=new;
        return t;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return t;
}
void deletemiddle(struct node *h,int len)
{
    struct node *temp,*prev;
    temp=h;
    if(temp==NULL || temp->next==NULL)
    {
        printf("Deletion is not possible");
    }
    else
    {
        temp=h;
        for(int i=0;i<len/2-1;i++)
        {
            temp=temp->next;
        }
        prev=temp->next;
        temp->next=temp->next->next;
        free(prev);
        printf("After deleting the middle node...\n");
        printlist(h);
    }
}

void printlist(struct node *t)
{
    struct node *temp=t;
    if(temp==NULL)
    {
        printf("List is NULL");
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
int main()
{
    int i,n,k;
    printf("Enter the lenght of the list : ");
    scanf("%d",&n);
    
    struct Node *head;
    head=NULL;
    printf("Enter the node values : \n");
    for(i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        head=append(head,k);
    }
    deletemiddle(head,n);
    return 0;
}
