#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
};

void display(struct node*head)
{   
    struct node*dummy=head;
    
    printf("-DETAILS-\n");
    while(dummy->next!=head)
    {
        printf("%d   ",dummy->data);
        dummy=dummy->next;
    }
    printf("%d\n ",dummy->data);
}

struct node*addtoempty(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;

    head=temp;
    return head;
}

struct node*insertatbegin(struct node*head)
{
    struct node*temp=malloc(sizeof(struct node)),*tail;
    printf("Enter element to insert at beginning:\n");
    scanf("%d",&temp->data);
    tail=head->prev;
    tail->next=temp;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

struct node*insertatend(struct node*head)
{
    printf("Enter element to insert at end:\n");
    struct node*temp=malloc(sizeof(struct node));
    struct node*dummy=head;
    while(dummy->next!=head)
    {
        dummy=dummy->next;
    }
    scanf("%d",&temp->data);
    dummy->next=temp;
    temp->prev=dummy;
    temp->next=head;
    return head;
}

struct node* insertatk(struct node* head)
{
    int pos;
    printf("After what position we need to add?\n");
    scanf("%d",&pos);

    struct node*temp=malloc(sizeof(struct node));
    struct node*dummy=head;

    printf("Enter element to insert after kth position:\n");
    scanf("%d",&temp->data);

    while(pos>1)
    {
        pos--;
        dummy=dummy->next;
    }
    temp->next=dummy->next;
    dummy->next=temp;
    temp->prev=dummy;

    return head;
}

struct node*deleteatstart(struct node*head)
{
    struct node*tail;
    struct node*dummy;
    dummy=head;
    tail=dummy->prev;
    head=dummy->next;
    tail->next=head;
    head->prev=tail;
    free(dummy);
    dummy=NULL;
    return head;
}

struct node*deleteatend(struct node*head)
{
    struct node*dummy1=head;
    struct node*dummy2=head;

    while(dummy2->next!=head)
    {
        dummy1=dummy2;
        dummy2=dummy2->next;   
    }
    dummy1->next=head;
    head->prev=dummy1;
    free(dummy2);
    return head;
}

struct node*deleteatk(struct node*head)
{
    int pos;
    struct node*dummy=head;
    struct node*dummy2;

    printf("Enter which node to delete:\n");
    scanf("%d",&pos);

    while(pos>1)
    {
        dummy=dummy->next;
        pos--;
    }
    dummy2=dummy->prev;
    dummy2->next=dummy->next;
    dummy->next->prev=dummy2;
    free(dummy);
    dummy=NULL;
    return head;
}
/*
struct node*reverse(struct node*head)
{
        printf("Reverse:\n");
    struct node*dummy1=head;
    struct node*dummy2=dummy1->next;

    dummy1->next=NULL;
    dummy1->prev=dummy2;

    while(dummy2!=NULL)
    {
        dummy2->prev=dummy2->next;
        dummy2->next=dummy1;

        dummy1=dummy2;
        dummy2=dummy2->prev;
    }
    head=dummy1;
    return head;    
}
*/
int main()
{   int first;
    struct node*head=NULL;

    /*
    int i,n;
    printf("Enter number of elements:\n");
    scanf("%d",&n);

    struct node* head=(struct node *)malloc(sizeof(struct node));
    printf("Enter first Student ID:\n");
    scanf("%d",&head->data);
    head->prev=head;
    head->next=head;

    struct node*temp;
    temp=head;

    for(i=0;i<n-1;i++)
    {
        struct node*current=(struct node *)malloc(sizeof(struct node));
        printf("Enter %d studentid:\n",i+2);
        scanf("%d",&current->data);
        temp->next=current;
        current->prev=temp;
        current->next=head;
        head->prev=current;
        temp=current;
    }
    */
    printf("What is your first element?:\n");
    scanf("%d",&first);

    head=addtoempty(head,first);
    head=insertatbegin(head);
    head=insertatend(head);
    //head=insertatk(head);

    //head=deleteatstart(head);
    //head=deleteatend(head);
    //head=deleteatk(head);
    head=reverse(head);

    display(head);
    return 0;
}