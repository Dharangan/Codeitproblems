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
void checkpalindrome(struct node *h,int len)
{
    struct node *temp;
    temp=h;
    int a[1000];
    int i,j,k;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=h;
        for(int i=0;i<len;i++)
        {
            a[i]=temp->data;
            temp=temp->next;
        }
        i=0;
        j=len-1;
        while(a[i]==a[j])
        {
            i++;
            j--;
           if(i==j || i+j==len-1)
           {
              printf("The given linked list is a palindrome");
              exit(0);
           }
        }
    
        printf("The given linked list is not a palindrome");
        
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
    checkpalindrome(head,n);
    return 0;
}
