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
void reverse(struct node* head) 
{ 
    struct node* prev = NULL; 
    struct node* current = head; 
    struct node* nexts = NULL; 
    while (current != NULL) { 
        nexts = current->next; 
        current->next = prev; 
        prev = current; 
        current = nexts; 
    } 
    head = prev; 
} 
void sumOflists(struct node *h1, struct node *h2)
{
    struct node *temp,*temp1,*temp2,*head3;
    temp1=h1;
    temp2=h2;
    head3=NULL;
    int sum=0,carry=0;
    while(temp1!=NULL && temp2!=NULL)
    {
        sum=carry+temp1->data+temp2->data;
        head3=append(head3,sum%10);
        carry=sum>9 ? 1 : 0;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp=(temp1==NULL) ? temp2:temp1;
    while(temp!=NULL)
    {
        sum=carry+temp->data;
        head3=append(head3,sum%10);
        carry= sum >9 ? 1:0;
        temp=temp->next;
    }
    if(carry)
    {
        head3=append(head3,1);
    }
   // printlist(head3);
    reverse(head3);
    printlist(head3);
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
    struct Node *head1,*head2;
    head1=head2=NULL;
    int i,j,a,b;
    printf("Enter 2 numbers : \n");
    scanf("%d %d",&a,&b);
    if(a==0)
    {
        head1=append(head1,0);
    }
    if(b==0)
    {
        head2=append(head2,0);
    }
    while(a>0)
    {
        head1=append(head1,a%10);
        a/=10;
    }
    while(b>0)
    {
        head2=append(head2,b%10);
        b/=10;
    }
    
    sumOflists(head1,head2);
    return 0;
}
