/*
Using the Double Linked list perform follwing operations. Create a function for all the operation. After
every operation call print list function.
1. Insert n integer data in sorted form using InsertAtEnd(). e.g:- 1, 2, 3, 5, 6, 7
2. On the above sorted doubly linked list of positive distinct elements, the task is to write function (FindPairsSum()) that find pairs in a doubly-linked list whose sum is equal to given value x?
*/

#include<stdio.h>
#include<stdlib.h>
struct stud
{
  int data;
  struct stud *prev;
  struct stud *next;
};
int main()
{
  int n,i;  
    printf("Enter the number of elements of linked list \n");
    scanf("%d",&n);
    struct stud *head=NULL,*temp,*prev1;
    for(i=0;i<n;i=i+1)
    {
        struct stud *p;
        p=malloc(sizeof(struct stud));
        printf("Enter the details of %dth student \n",i+1);
        scanf("%d",&p->data);
        p->next=NULL;
        p->prev=NULL;
        if(head==NULL)
        head=p;
        else
        {
            p->prev=prev1;
            prev1->next=p;
        }
        prev1=p;
    }
    temp=head;
    i=1;
    while(temp!=NULL)
    {
        printf("%dth student data is %d \n",i,temp->data);
        temp=temp->next;
        i=i+1;
    }
    int x,sum=0,count=0;
    printf("Enter the sum you want to check \n");
    scanf("%d",&x);
   
    temp=head;
    for(i=0;i<n;i=i+1)
    {
        sum=0;
        prev1=temp->next;
    while(prev1!=NULL)
    {
        sum=temp->data+prev1->data;
        if(sum>x)
        break;
        else if(sum==x)
        {
            printf("%d + %d = %d \n",temp->data,prev1->data,x);
            count=1;
            break;
        }
        else
        prev1=prev1->next;
        sum=0;
    }
    temp=temp->next;
    }
   
    if(count==0)
    printf("No such pair exist \n");
    return(0);
}

/*
Implement Circular Single Linked List
1. Insert an item at the end
2. Insert an item at the beginning
3. Count the length of list
4. Print each element of the list
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *tail,*temp;
    tail=0;
    int choice,option,count=0;
    while(choice)
    {
        printf("Where you want to add: \n1.Beginning  or  2.Ending\n");
        scanf("%d",&option);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter a value to add: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(option==1)
        {
            count++;
            if(tail==0)
            {
                tail=newnode;
                tail->next=newnode;
            }
            else
            {
                newnode->next=tail->next;
                tail->next=newnode;
            }
        }
        else if(option==2)
        {
            count++;
            if(tail==0)
            {
                tail=newnode;
                tail->next=newnode;
            }
            else
            {
                newnode->next=tail->next;
                tail->next=newnode;
                tail=newnode;
            }
        }
        else
            printf("Invalid Option\n");
        printf("Do you want to continue (0 or 1) : ");
        scanf("%d",&choice);
    }
    printf("Length of list:%d\n",count);
    printf("Elements in the List:\n");
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
    return(0);
}
