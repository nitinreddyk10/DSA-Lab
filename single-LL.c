#include<stdio.h>
#include<stdlib.h>

struct node
{
    int studid;
    char name[9];
    struct node*next;
};

void nodecount(struct node*head)
{
    int count=0;
    if(head==NULL)
    {
        printf("Empty Set:\n");
    }
    struct node*dummy=head;
    while(dummy!=NULL)
    {
        count=count+1;
        dummy=dummy->next;
    }
    printf("Count=%d",count);
}

struct node* insertatend(struct node*head)
{
    struct node *dummy=head;
    struct node* newnode=malloc(sizeof(struct node));

    printf("Enter the last rollno to be added:\n");
    scanf("%d",&newnode->studid);
    printf("Enter the last name:\n");
    scanf("%s",newnode->name);

    while(dummy->next!=NULL)
    {
        dummy=dummy->next;
    }

    dummy->next=newnode;
    newnode->next=NULL;

return head;
}

struct node* insertatstart(struct node*head)
{
    struct node* newnode=malloc(sizeof(struct node));
    struct node*dummy;

    printf("Enter rollno to be added at start:\n");
    scanf("%d",&newnode->studid);
    printf("Enter name to be added at start:\n");
    scanf("%s",newnode->name);

    newnode->next=head;
    head=newnode;

    return head;
}

struct node* deleteatend(struct node*head)
{
     
        struct node*dummy1=head;
        struct node*dummy2;

        while(dummy1->next!=NULL)
        {
            dummy2=dummy1;
            dummy1=dummy1->next;
        }
        if(head->next!=NULL)
        dummy2->next=NULL;
        free(dummy1);
    return head;
}

struct node* deleteatstart(struct node*head)
{
    struct node* temp=head;
    head=temp->next;
    free(temp);
    return head;
}

struct node* deleteatk(struct node*head)
{
    int pos,i=1;
    printf("enter which position to delete:");
    scanf("%d",&pos);
    struct node* temp=head;
    struct node *nextnode;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    return head;
}

struct node* insertatk(struct node*head)
{   int pos;
    printf("Enter after which node to add\n");
    scanf("%d",&pos);

    struct node*temp=head;
    struct node*newnode=malloc(sizeof(struct node));
    printf("Enter element to insert:\n");
    scanf("%d",&newnode->studid);
    printf("enter name:\n");
    scanf("%s",newnode->name);

    int count=0;
    while(pos==count)
    {
        temp=temp->next;
        count++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

int main()
{
    int n,i;
    printf("Enter number of elements:\n");
    scanf("%d",&n);

    struct node* head=(struct node *)malloc(sizeof(struct node));
    printf("Enter first Student ID:\n");
    scanf("%d",&head->studid);
    printf("Name:\n");
    scanf("%s",head->name);
    head->next=NULL;

    struct node*temp=head;

    for(i=0;i<n-1;i++)
    {
        struct node*current=(struct node *)malloc(sizeof(struct node));
        printf("Enter %d studentid:\n",i+2);
        scanf("%d",&current->studid);
        printf("Enter %d name\n",i+2);
        scanf("%s",current->name);
        current->next=NULL;
        temp->next=current;
        temp=current;
    }

//head=insertatend(head);
//head=insertatstart(head);

//head=deleteatend(head);
//head=deleteatstart(head);

//head=deleteatk(head);
//head=insertatk(head);

    printf("\nDetails:\n");
        temp=head;
        while(temp!=NULL)
        {
        printf("studentid: %d\n",temp->studid);
        printf("name: %s\n",temp->name);
        temp=temp->next;
        }

        //nodecount(head);

        return 0; 
}