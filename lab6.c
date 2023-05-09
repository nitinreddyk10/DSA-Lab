/*
We are given a string having parenthesis like (((X))(((Y )))) Write a code which finds the maximum depth
of balanced parenthesis, like 4 in the above example. Since ‘Y’ is surrounded by 4 balanced parentheses.
If parenthesis is unbalanced then return -1. (Use Array Implementation)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100

struct lifo
{
  char string[MAXSIZE];
  int top;
};

 typedef struct lifo stack;
    void create (stack*s)
    {
        s->top=-1;
    }
    
    void push(stack*s,char p)
    {
        if(s->top==(MAXSIZE-1))
        {
            printf("\noverflow\n");
            exit(-1); 
        }
        else
        {
            s->top++;
            s->string[s->top]=p;
        }
    }
    
    char pop(stack*s)
    {
        if(s->top==-1)
        {
            printf("\nUnderflow\n");
            exit(-1);
        }
        else
        {
            return  s->string[s->top--];
        }
    }

void main()
{
    stack a;
    int max,count=0,u,fu,k=0;
    create(&a);
    printf("Enter string:\n");
    char m[MAXSIZE],x;
    scanf("%s",m);
    int i,op=0,cl=0;
    int y=strlen(m);
    
    for(i=0;i<y;i++)
    {
        if(m[i]=='(')
        {
            op++;
            count++;
        }
        if(m[i]==')')
        {
            cl++;
            count--;
        }
        if(count<0)
        fu=1;
    }

printf("open=%d,close=%d\n",op,cl);
if(cl!=op || fu==1)
{
    printf("Parenthesis unbalanced\n");
}
else
{
    count=0;
    for(i=0;i<y;i++)
    {
        if(m[i]=='(')
        {
            push(&a,m[i]);
            count++;
        }
        
        if(m[i]==')')
        {
            x=pop(&a);
            k++;
            count--;
        }
        if(k==1)
        {
            max=count+1;
        }
        if(max<count)
        {
            max=count;
        }
    }
    printf("%d",max);
}
}

/*
Implement the Queue using the concept of a Circular Array of maximum size 4. Insert only the integer
value in your queue. Perform following operations
• Insertion (4 times)
• Deletion (2 times)
• Insertion (3 times)
• Deletion (3 times)
While implementing the insertion and deletion operations, check all the corner cases wherever it is appli-
cable and do the necessary action.
• Overflow
• Underflow
• Single element
• Empty queue
*/

#include<stdio.h>

#define MAX 4

int a[MAX];

int front=-1,back=-1;

void addquefront()
{
    int x;
    printf("Enter to add : ");
    scanf("%d",&x);
    if((front==0 && back==MAX-1) || front==back+1)
        printf("Queue Overflow\n");
    else if(front==-1 && back==-1)
    {
        front=back=0;
        a[front]=x;
        printf("Insertion done\n");
    }
    else if(front==0)
    {
        front=MAX-1;
        a[front]=x;
        printf("Insertion done\n");
    }
    else
    {
        front--;
        a[front]=x;
        printf("Insertion done\n");
    }
}

void addquerear()
{
    int x;
    printf("Enterto add : ");
    scanf("%d",&x);
    if((front==0 && back==MAX-1) || front==back+1)
        printf("Queue Overflow\n");
    else if(front==-1 && back==-1)
    {
        front=back=0;
        a[back]=x;
        printf("Insertion donel\n");
    }
    else if(back==MAX-1)
    {
        back=0;
        a[back]=x;
        printf("Insertion Succesful\n");
    }
    else
    {
        back++;
        a[back]=x;
        printf("Insertion done\n");
    }
}

void delquefront()
{
    if(front==-1 && back==-1)
        printf("Queue Underflow\n");
    else if(front==back)
        front=back-1;
    else if(front==MAX-1)
    {
        printf("Deleted elemnt : %d\n",a[front]);
        front=0;
    }
    else
    {
        printf("Deleted element : %d\n",a[front]);
        front++;
    }
}

void delquerear()
{
    if(front==-1 && back==-1)
        printf("Queue Underflow\n");
    else if(front==back)
        front=back-1;
    else if(back==0)
    {
        printf("Deleted element : %d\n",a[front]);
        back=MAX-1;
    }
    else
    {
        printf("Deleted element : %d\n",a[front]);
        back++;
    }
}

void print()
{
    int i=front;
    printf("Elements: \n");
    while(i!=back)
    {
        printf("%d ",a[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n",a[i]);
}

int main()
{
    int ch,x,temp;
    while(temp!=0)
    {
        printf("Operation??: \n");
        printf("1. insert front\n");
        printf("2. insert back\n");
        printf("3. delete front\n");
        printf("4. delete back \n");
        printf("5. remaining display\n");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1 : addquefront();
                   break;
          case 2 : addquerear();
                   break;
          case 3 : delquefront();
                   break;
          case 4 : delquerear();
                   break;
          case 5 : print();
                   break;
          default : printf("Invalid Choice\n");
                    break;
        }
        printf("press 1 to continue and 0 to exit : ");
        scanf("%d",&temp);
    }
    return(0);
}

/*
Write a code to convert infix to postfix using linked list. Consider following operator in your expression
^,∗, /, +, −. Follow the precedence ordering ^ , > (∗, /) > (+, −) and left to right associativity for same
precedence for converting the expression.  (Using Linked List)

Ex: Infix string=a + b ∗ (c ^d − e) − i

Postfix string= abcd ^ e − +i−
*/