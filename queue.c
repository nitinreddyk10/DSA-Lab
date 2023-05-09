// USING ARRAYS
/*
#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("Overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }   
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Peeked element:%d\n",queue[front]);
    }
}

int main()
{
    int k;
    printf("How many elements to be inserted?\n");
    scanf("%d",&k);

    for(int i=0;i<k;i++)
    {
        int x;
        printf("Enter element %d\n",i+1);
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Dequeued Element:%d\n",queue[front]);
    dequeue();
    peek();
    printf("Displaying\n");
    display();
}
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*front;
struct node*rear;

void enqueue(int x)
{
    struct node*newnode=malloc(sizeof(struct node));

    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node*temp;
    temp=front;
    if(front=rear=NULL)
    {
        printf("Empty:\n");
    }
    else
    {
        front=temp->next;
        printf("deleted element:%d\n",temp->data);
        free(temp);
    }
}

void display()
{
    struct node*temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Empty queue\n");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
     if(front==NULL && rear==NULL)
    {
        printf("Empty queue\n");
    }
    else
    {
        printf("peek element:%d\n",front->data);
    }
}

int main()
{
    int k;
    printf("How many elements to be inserted?\n");
    scanf("%d",&k);

    for(int i=0;i<k;i++)
    {
        int x;
        printf("Enter element %d\n",i+1);
        scanf("%d",&x);
        enqueue(x);
    }

    dequeue();
    peek();
    printf("Displaying\n");
    display();
}