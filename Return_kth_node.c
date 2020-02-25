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
void findkthnode(struct node *h,int k)
{
    struct node *temp;
    temp=h;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        temp=h;
        for(int i=0;i<len-k;i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            printf("The kth node value is : %d ",temp->data);
        }
        else
        {
            printf("kth node cannot be found");
        }
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
    printf("Ener the node values : \n");
    for(i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        head=append(head,k);
    }
    printf("Enter the k value : \n");
    scanf("%d",&k);
    findkthnode(head,k);
    return 0;
}
