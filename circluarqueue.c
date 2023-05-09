// USING ARRAY
/*
#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear=(rear+1)%N;
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
        printf("dequeued element=%d\n",queue[front]);
        front=(front+1)%N;
    }
}

void display()
{
    int i=0;
    if(front==-1 && rear==-1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Queue is:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
            i=(i+1)%N;
        }
    }
}

void peek()
{
    printf("peek %d\n",queue[front]);
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
    display();
}
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

struct node
{
    int data;
    struct  node*next;
};

struct node*front=0;
struct node*rear=0;

void enqueue(int x)
{
    struct  node*newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;

    if(rear==NULL)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue()
{
    struct node*temp=front;
    if(front==NULL&&rear==NULL)
    {
        printf("Empty\n");
    }
    else if(front==rear)
    {
        printf("Dequeued:%d\n",temp->data);
        front=rear=0;
        free(temp);
    }
    else;
    {
        printf("Dequeued:%d\n",temp->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display()
{
    struct node*temp=front;
    if(front==NULL&&rear==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("details:\n");
        while(temp->next!=front)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("%d  ",temp->data);
    }
}

void peek()
{
    if(front==NULL&&rear==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("peek=%d\n",front->data);
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
    display();
}