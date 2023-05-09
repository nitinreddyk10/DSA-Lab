#include<stdio.h>
#include<stdlib.h>

struct student
{
    int rollno;
    char name;
    int courseid[4];
    int marks[4];
    /*
    char Name;
    int Course Id[4];
    int Marks[4];
    */
    struct student*next;
};

struct student *createlist(int n)
{
    struct student *stud,*head,*temp;
    int i,j;
    
    for(i=0;i<n;i++)
    {
        stud=(struct student*)malloc(sizeof(struct student));
        printf("Enter roll no and name of student %d\n",i+1);
        scanf("%d %c",&stud->rollno,&stud->name);
        for(j=0;j<4;j++)
        {
            printf("enter course- %d ID :",j+1);
            scanf("%d",&stud->courseid[j]);
            printf("enter course- %d Marks :",j+1);
            scanf("%d",&stud->marks[j]);
        }
        stud->next=0;
        if(i==0)
        head=temp=stud;
        else
        {
            temp->next=stud;
            temp=stud;
        }
        printf("-----------------------------------------------");
    }
    return head;
}

void display(struct student*head)
{
    struct student*temp;
    temp=head;
    printf("Student details and marks:\n");
    int j;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("Roll no:%d\n",temp->rollno);
            printf("Student Name: %c\n",temp->name);
            for(j=0;j<4;j++)
            {
                printf("%d ID : %d",j+1,temp->courseid[j]);
                printf("%d ID : %d",j+1,temp->marks[j]);
            }
            printf("---------\n");
            temp=temp->next;
        }
    }
}

int countlist(struct student *head)
{
    struct student *temp=head;
    int count=0;
    if (temp==0)
    count=0;
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;
}

struct student *insertatk(struct student *head,struct student *newnode,int pos,int n)
{
    struct student *temp=head;
    int i=1;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else if(pos>n)
    {
        struct student *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}

struct student *deleteatbegin(struct student *head)
{
    struct student *temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct student *deleteatend(struct student *head)
{
    struct student *temp=head;
    struct student *prevnode;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    else
    {
        prevnode->next=NULL;
        free(temp);
    }
    return head;
}

struct student *deleteatk(struct student *head,int l,int n)
{
    int i=1;
    struct student *temp;
    temp=head;
    struct student *nextnode;
    if(temp==NULL)
    printf("List is empty\n:");
        else
        {
            if(l==1)
            {
                head=head->next;
                free(temp);
            }
            else if(l>n)
            printf("position %d does not exist\n",l);
            else
            {
                while(i<l-1)
                {
                    temp=temp->next;
                    i++;
                }
                nextnode=temp->next;
                temp->next=nextnode->next;
                free(nextnode);
            }
        }
        return head;
}

void displayfromend(struct student *head,int k,int n,int count)
{
    int loc=count-k+1,i=1;
    struct student *temp=head;
    if(loc==1)
    {
        printf("roll no: %d\n",temp->rollno);
        printf("student name: %d\n",temp->name);
        for(int j=0;j<4;j++)
        {
            printf("course -%d ID : %d\n",j+1,temp->courseid[j]);
            printf("course -%d marks : %d\n",j+1,temp->marks[j]);
        }
    }
    else if(i<loc)
    {
        printf("Invalid position\n");
    }
    else
    {
        while(i<loc)
        {
            temp=temp->next;
            i++;
        }
         printf("roll no: %d\n",temp->rollno);
        printf("student name: %d\n",temp->name);
        for(int j=0;j<4;j++)
        {
            printf("course -%d ID : %d\n",j+1,temp->courseid[j]);
            printf("course -%d marks : %d\n",j+1,temp->marks[j]);
        }
        printf("\n");
    }
}

struct student *swaplastfirst(struct student *head)
{
    struct student *temp,*prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
        prevnode->next=NULL;
        temp->next=NULL;
        head=temp;
        return head;
}

void reverselist(struct student*head)
{
    struct student *temp;
    int j;
    printf("List in reverse order:\n");
    temp=head;
    if(head==NULL)
    return;
    printf("Roll no : %d\n",temp->rollno);
    printf("student name : %d\n",temp->name);
    for(int j=0;j<4;j++)
        {
            printf("course -%d ID : %d\n",j+1,temp->courseid[j]);
            printf("course -%d marks : %d\n",j+1,temp->marks[j]);
        }
        printf("------------\n");
        reverselist(temp->next);
}

/* struct student *deletelist(struct student *head)
{
  struct student *temp;
  temp=head;
  while(temp!=NULL)
  {
      struct student *dummy;
      dummy=temp;
      free(dummy);
      temp=temp->next;
  }
  return head;
}
*/

int main()
{
int n,count;
printf("enter no.of students in list");
scanf("%d",&n);

struct student *head=createlist(n);
printf("list of %d students :\n",n);
display(head);
int pos;
printf("at which position do you wanna add?\n");
scanf("%d",&pos);
struct student *newnodek=createlist(1);
head=insertatk(head,newnodek,pos,n);

printf("list after adding a student at position - %d :\n",pos);
display(head);
printf("list after deleting first student\n");
head=deleteatbegin(head);
display(head);
printf("list after deleting last student\n");
printf("------------\n");
head=deleteatend(head);
display(head);

int pos1;
printf("at what position do you wanna delete:\n");
scanf("%d",&pos1);
printf("list after deleting student %d:\n",pos1);
head=deleteatk(head,pos1,n);
if(head==0)
{
printf("list is empty\n");
}
else
display(head);
int pos2;
printf("Which student from last you want\n");
scanf("%d",&pos2);
printf("details of %d student from last is: \n",pos2);
count=countlist(head);
displayfromend(head,pos2,n,count);
head=swaplastfirst(head);
printf("After movng last one to first:\n");
display(head);
printf("After reversing\n");
reverselist(head);
count=countlist(head);
while(count--)
{
    head=deleteatbegin(head);
}
printf("After deleting,remaining list=\n");
display(head);
return 0;
}