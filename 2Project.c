#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char sender[20];
    char message[150];
    struct node *next;
};

typedef struct node chat;

void display(chat *head)
{
    chat *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Chat is empty\n");
    }
    while(temp!=NULL)
    {
        printf("%s : ",temp->sender);
        printf("%s\n",temp->message);
        temp=temp->next;
    }
}

chat *send(chat *head)
{
    chat *newchat,*temp;
    newchat=(chat *)malloc(sizeof(chat));
    printf("Enter the user name : ");
    scanf(" %[^\n]s",newchat->sender);
    printf("Enter Message(Max 150 Characters): ");
    scanf(" %[^\n]s",newchat->message);
    newchat->next=NULL;
    if(head==NULL)
    {
        head=newchat;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newchat;
    }
    return(head);
}

chat *delete(chat *head)
{
    int k;
    printf("Enter the message number(from top to bottom) to be deleted : ");
    scanf("%d",&k);
    chat *temp,*p;
    temp=head;
    int count=1;
    if(k==1)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        while(count<k-1)
        {
            count++;
            temp=temp->next;
        }
        p=temp->next;
        temp->next=p->next;
        free(p);
    }
    return(head);
}

int main()
{
    int n;
    printf("Enter the number of contacts in the mobile(Including Yours) : ");
    scanf("%d",&n);
    int connections,cno=0;
    connections=n*(n-1)/2;
    chat *person[connections];
    for(int i=0; i<connections; i++)
    {
        person[i]=NULL;
    }
    char name[n][20];
    for(int i=0; i<n; i++)
    {
        printf("Enter the name of contact-%d : ",i+1);
        scanf(" %[^\n]s",name[i]);
    }
    int user,receiver;
    printf("Enter your serial number:-\n");
    for(int i=0; i<n; i++)
    {
        printf("%d.%s   ",i+1,name[i]);
    }
    printf("\n");
    printf("Input : ");
    scanf("%d",&user);
    int ch=1;
    int choice;
    while(ch==1)
    {
        printf("What action do you want to perform? 1.Send Message 2.Display messages 3.Delete Message 4.Change user : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the serial number of the other person : ");
            for(int i=0; i<n; i++)
            {
                printf("%d.%s   ",i+1,name[i]);
            }
            printf("\n");
            printf("Input : ");
            scanf("%d",&receiver);
            if(user==receiver)
            {
                printf("Invalid Command\n");
            }
            else
            {
                int l,m;
                int min,max;
                if(user<receiver)
                {
                    min=user;
                    max=receiver;
                }
                else
                {
                    min=receiver;
                    max=user;
                }
                for(l=1; l<min; l++)
                {
                    for(m=0; m<n-l; m++)
                    {
                        cno++;
                    }
                }
                m=l+1;
                while(m<=n)
                {
                    cno++;
                    if(m==max)
                    break;
                    m++;
                }
                person[cno-1]=send(person[cno-1]);
                cno=0;
            }
        }
        else if(choice==2)
        {
            printf("Enter the serial number of the other person : ");
            for(int i=0; i<n; i++)
            {
                printf("%d.%s   ",i+1,name[i]);
            }
            printf("\n");
            printf("Input : ");
            scanf("%d",&receiver);
            if(user==receiver)
            {
                printf("Invalid Command\n");
            }
            else
            {
                int l,m;
                int min,max;
                if(user<receiver)
                {
                    min=user;
                    max=receiver;
                }
                else
                {
                    min=receiver;
                    max=user;
                }                
                for(l=1; l<min; l++)
                {
                    for(m=0; m<n-l; m++)
                    {
                        cno++;
                    }
                }
                m=l+1;
                while(m<=n)
                {
                    cno++;
                    if(m==max)
                    break;
                    m++;
                }
                display(person[cno-1]);
                cno=0;
            }            
        }
        else if(choice==3)
        {
            printf("Enter the serial number of the other person : ");
            for(int i=0; i<n; i++)
            {
                printf("%d.%s   ",i+1,name[i]);
            }
            printf("\n");
            printf("Input : ");
            scanf("%d",&receiver);
            if(user==receiver)
            {
                printf("Invalid Command\n");
            }
            else
            {
                int l,m;
                int min,max;
                if(user<receiver)
                {
                    min=user;
                    max=receiver;
                }
                else
                {
                    min=receiver;
                    max=user;
                }
                for(l=1; l<min; l++)
                {
                    for(m=0; m<n-l; m++)
                    {
                        cno++;
                    }
                }
                m=l+1;
                while(m<=n)
                {
                    cno++;
                    if(m==max)
                    break;
                    m++;
                }
                display(person[cno-1]);
                person[cno-1]=delete(person[cno-1]);
                display(person[cno-1]);
                cno=0;
            }           
        }
        else if(choice==4)
        {
            printf("Enter your serial number:-\n");
            for(int i=0; i<n; i++)
            {
                printf("%d.%s   ",i+1,name[i]);
            }
            printf("\n");
            printf("Input : ");
            scanf("%d",&user);
        }
        else
        {
            printf("Invalid Command\n");
        }
        printf("Do you wish to continue? : Press 1 to Yes or any other key to exit : ");
        scanf("%d",&ch);
    }
    return(0);
}