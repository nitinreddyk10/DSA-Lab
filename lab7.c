/*
1. Implement Deque using doubly linked list.  (Marks-10)
2. Implement Stack and Queue using Deque. (Marks-5)
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next,*prev;
};
struct node*front=NULL;
struct node*rear=NULL;
void insertend(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
void insertfront(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        front->prev=newnode;
        newnode->next=front;
        front=newnode;
    }
}
void display()
{
    struct node*temp;
    if(front==0 && rear==0)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("the list is\n");
        temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void deletefront()
{
    struct node*temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("list is empty\n");
    }
    else if(front==rear)
    {
        front=rear=0;
    }
    else
    {
        front=front->next;
        front->prev=NULL;
        free(temp);
    }
}
void deleteend()
{
    struct node*temp;
    temp=rear;
    if(front==0 && rear==0)
    {
        printf("list is empty\n");
    }
    else if(front==rear)
    {
        front=rear=0;
    }
    else
    {
        rear=rear->prev;
        rear->next=NULL;
        free(temp);
    }
    
}
int main()
{
    int choice1,n,x,choice2,y,m,z,choice3,choice4;
    while(choice1)
    {
        printf("enter 1)insertfront 2)insertend 3)deletefront 4)deleteend 5)displaylist\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("enter the number to insert\n");
            scanf("%d",&x);
            insertfront(x);
        }
        else if(n==2)
        {
            printf("enter the number to insert\n");
            scanf("%d",&x);
            insertend(x);
        }
        else if(n==3)
        {
            deletefront();
        }
        else if(n==4)
        {
            deleteend();
        }
        else if(n==5)
        {
            display();
        }
        printf("enter 1)continue 0)to go to stack or queue \n");
        scanf("%d",&choice1);
    }
    while(choice2)
    {
        printf("enter to implement 1)stack 2)queue \n");
        scanf("%d",&m);
        if(m==1)
        {
            while(choice3)
            {
            printf("enter 1)push 2)pop 3)display\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("enter the number to insert\n");
            scanf("%d",&y);
            insertfront(y);
            }
            else if(z==2)
            {
                deletefront();
            }
            else if(z==3)
            {
                display();
            }
        printf("enter 1)continue 0)exit\n");
        scanf("%d",&choice3);
            }
        }
        if(m==2)
        {
            while(choice4)
            {
            printf("enter 1)enqueue 2)dequeue 3)display\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("enter the number to insert\n");
            scanf("%d",&y);
            insertend(y);
            }
            else if(z==2)
            {
                deletefront();
            }
            else if(z==3)
            {
                display();
            }
        printf("enter 1)continue 0)exit\n");
        scanf("%d",&choice4);
            }
        }
         printf("enter 1)continue to stack or queue 0)exit code\n");
        scanf("%d",&choice2);
    }
    
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*head,*tail;


struct node* create(int data)
{
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void essentials()
{
    head=create(0);
    tail=create(0);
    head->next=tail;
    tail->prev=head;
}

void enqueuefront(int data)
{
    struct node*newnode,*temp;
    newnode=create(data);
    temp=head->next;
    head->next=newnode;
    newnode->next=temp;
    temp->prev=newnode;
}

void enqueuerear(int data)
{
    struct node*newnode,*temp;
    newnode=create(data);
    temp=tail->prev;
    tail->prev=newnode;
    newnode->next=tail;
    newnode->prev=temp;
    temp->next=newnode;
}

void dequeuefront()
{
    struct node*temp;
    if(head->next==tail)
    {
        printf("Empty Queue:\n");
    }
    else
    {
        temp=head->next;
        head->next=temp->next;
        temp->next->prev=head;
        free(temp);
    }
}

void dequeuerear()
{
    struct node*temp;
    if(tail->prev==head)
    {
        printf("Empty Queue:\n");
    }
    else
    {
        temp=tail->prev;
        tail->prev=temp->prev;
        temp->prev->next=tail;
        free(temp);
    }
}


void display()
{
    printf("ELEMENTS:\n");
    struct node*temp;
    temp=head->next;
    while(temp!=tail)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{   int data,c;
    essentials();
    printf("1.Enq at front\n2.Enq at back\n3.deQ at front\n4.deQ at back\n5.to display\n6.exit\n");
    while(1)
    {
        printf("Enter choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
            printf("Enter data to insert at front\n");
            scanf("%d",&data);
            enqueuefront(data);
            break;
            }
            case 2:
            {
            printf("Enter data to insert at back\n");
            scanf("%d",&data);
            enqueuerear(data);
            break;
            }
            case 3:
            {
                dequeuefront();
                break;
            }
            case 4:
            {
                dequeuerear();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
            {
                exit(-1);
            }
        }
    }
}  
*/
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*front=NULL;
struct node*rear=NULL;
void insertend(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
void insertfront(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        front->prev=newnode;
        newnode->next=front;
        front=newnode;
    }
}
void display()
{
    struct node*temp;
    if(front==0 && rear==0)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("List:\n");
        temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void deletefront()
{
    struct node*temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty list\n");
    }
    else if(front==rear)
    {
        front=rear=0;
    }
    else
    {
        front=front->next;
        front->prev=NULL;
        free(temp);
    }
}
void deleteend()
{
    struct node*temp;
    temp=rear;
    if(front==0 && rear==0)
    {
        printf("liempty list\n");
    }
    else if(front==rear)
    {
        front=rear=0;
    }
    else
    {
        rear=rear->prev;
        rear->next=NULL;
        free(temp);
    }
    
}
int main()
{
    int choice1,choice2,choice3,choice4,n,x,y,m,z;
    printf("Enter 1)Insertfront \n2)Insertend \n3)Deletefront \n4)Deleteend \n5)Displaylist\n");
    while(choice1)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("enter the number to insert at start\n");
            scanf("%d",&x);
            insertfront(x);
        }
        else if(n==2)
        {
            printf("enter the number to insert at end\n");
            scanf("%d",&x);
            insertend(x);
        }
        else if(n==3)
        {
            deletefront();
        }
        else if(n==4)
        {
            deleteend();
        }
        else if(n==5)
        {
            display();
        }
        printf("enter 1 to continue\n 0 to go to stack or queue \n");
        scanf("%d",&choice1);
    }
    while(choice2)
    {
        printf("enter to implement \n1)stack 2)queue \n");
        scanf("%d",&m);
        if(m==1)
        {
            while(choice3)
            {
            printf("enter 1)push 2)pop 3)display\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("enter the number to insert\n");
            scanf("%d",&y);
            insertfront(y);
            }
            else if(z==2)
            {
                deletefront();
            }
            else if(z==3)
            {
                display();
            }
        printf("enter 1)continue 0)exit\n");
        scanf("%d",&choice3);
            }
        }
        if(m==2)
        {
            while(choice4)
            {
            printf("enter 1)enqueue 2)dequeue 3)display\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("enter the number to insert\n");
            scanf("%d",&y);
            insertend(y);
            }
            else if(z==2)
            {
                deletefront();
            }
            else if(z==3)
            {
                display();
            }
        printf("enter 1)continue 0)exit\n");
        scanf("%d",&choice4);
            }
        }
         printf("enter 1)continue to stack or queue 0)exit code\n");
        scanf("%d",&choice2);
    }
    return 0;
}
*/