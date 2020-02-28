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

struct node* insert(struct node *t,int val)
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

struct node* isLoop(struct node* head){
    struct node* slow = head;
    struct node* fast = head;
    
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    
    return fast;
}


struct node *detectLoop(struct node *head)
{
    struct node *loopnode = isLoop(head);
    
    if(loopnode == NULL)
        return loopnode;
    
    struct node* ptr1 = head;
    struct node* ptr2 = loopnode;
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr1;
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
    printf("Enter the lenght of the list (>=5) : ");
    scanf("%d",&n);
    
    struct node *head;
    head=NULL;
    printf("Enter the node values : \n");
    for(i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        head=insert(head,k);
    }
    
    // create a loop for testing
   head->next->next->next->next->next = head->next->next;
   
   struct node *loopnode=detectLoop(head);
   if(loopnode==NULL)
   {
       printf("There is no loop");
   }
   else
   {
       printf("Loop starts at %d",loopnode->data);
   }
   
   
    return 0;
}
