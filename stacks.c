//USING ARRAYS

#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
/*
struct lifo
{
    int arr[maxsize];
    int top;
};

typedef struct lifo stack;
stack s;

void create(stack*s)
{
    s->top=-1;
}

void push(stack*s)
{
    int n;
    printf("Enter element to push:\n");
    scanf("%d",&n);

    if(s->top==(maxsize-1))
    {
        printf("overflow\n");
        exit(-1);
    }
    else
    s->top++;
    s->arr[s->top]=n;
}

int pop(stack*s)
{
    if(s->top==-1)
    {
        printf("Underflow\n");
        exit(-1);
    }
    else
    {
        return(s->arr[s->top--]);
    }
}

int isempty(stack*s)
{
    if(s->top==-1)
    {
        printf("Yes,Empty\n");
    }
    else
    {
        printf("Not empty\n");
    }
}

int isfull(stack*s)
{
    if(s->top==(maxsize-1))
    {
        printf("Yes,full");
    }
    else
    {
        printf("Not full\n");
    }
}

void peek()
{
    if(top==-1)
    {
        printf("Empty");
    }
    else
    {
        printf("%d",stack[top]); or //arr[s->top]
    }
}

int main()
{
    int a,b;
    stack A,B;

    create(&A);
    create(&B);

    printf("How many elements do you want to put in A\n");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
    push(&A);
    }
    printf("How many elements do you want to put in B\n");
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
    push(&B);
    }

    //to move one element to other
    //now pop(&B) in scan place
    //to print all elements,we will create stack and push elements and print simultaneously
    //stack C;
    int choice;
    printf("print what stack 1 or 2?");
    scanf("%d",&choice);
    if(choice==1)
    {
    for(int i=0;i<a;i++)
    {
        printf("%d\n",pop(&A));
    }
    }
    else if(choice==2)
    {
        for(int i=0;i<b;i++)
        {
            printf("%d\n",pop(&B));
        }
    }

    printf("First elements of both are:\n");
    peek(&A);
    peek(&B);
    printf("Empty check\n");
    isempty(&A);
    isempty(&B);
    return 0;
}
*/
// USING LINKED LIST

struct lifo
{
int value;
struct  lifo*next;
};
typedef struct lifo stack;
stack*top;

void create(stack**top)
{
    *top=NULL;
}

void push(stack**top)
{
    int n;
    printf("Enter element to push:\n");
    scanf("%d",&n);

    stack*new=malloc(sizeof(stack*));
    if(new==NULL)
    {
        printf("Memory doesnot exist\n");
        exit(-1);
    }
    new->value=n;
    new->next=*top;
    *top=new;
}

int pop(stack**top)
{
    int t;
    stack*dummy;

    if(top==NULL)
    {
        printf("Empty\n");
        exit(-1);
    }
    else
    {
        t=(*top)->value;
        dummy=*top;
        *top=(*top)->next;

        free(dummy);
        return t;
    }
}

int isempty(stack*top)
{
    if(top->next==NULL)
    {
        printf("Yes,Empty\n");
        return 1;
    }
    else
    {
        printf("Not empty\n");
        return 0;
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d",top->data);
    }
}

int main()
{
    int a,b;
    stack *A,*B;

     printf("How many elements do you want to put in A\n");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
    push(&A);
    }
    printf("How many elements do you want to put in B\n");
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
    push(&B);
    }

    int choice;
    printf("print what stack 1 or 2?");
    scanf("%d",&choice);
    if(choice==1)
    {
    for(int i=0;i<a;i++)
    {
        printf("%d\n",pop(&A));
    }
    }
    else if(choice==2)
    {
        for(int i=0;i<b;i++)
        {
            printf("%d\n",pop(&B));
        }
    }

    printf("First elements of both are:\n");
    peek(&A);
    peek(&B);
    printf("Empty check\n");
    isempty(A);
    isempty(B);
    return 0;
}