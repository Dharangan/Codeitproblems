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
void removeduplicates(struct node *t)
{
    struct node *temp,*curr,*prev;
    temp=t;
    while(temp->next!=NULL)
    {
        curr=temp->next;
        while(curr->next!=NULL)
        {
            prev=curr;
            if(temp->data==curr->data)
            {
                temp->next=curr->next;
                curr=curr->next;
            }
            else
            {
                curr=curr->next;
            }

        }
        if(temp->data==curr->data)
        {
            prev->next=NULL;
        }
        temp=temp->next;
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
    int i,n;
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
    removeduplicates(head);
    printf("After removing the duplicates ....\n");
    printlist(head);
    return 0;
}
