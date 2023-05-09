/*
In your institute, a Tech feast is going to organize where various events will be conducted. Students from
the various institutions in Chennai will participate in different events. You have to write a program that
will create n events and for each event enroll M students.
You need to enter the following details of the students
Student_id, N ame, InstituteN ame, Age
After entering all the details, show the participants list based on the chosen event.
*/

#include<stdio.h>
struct fest
{
char studentid[20];
char name[30];
char institute[100];
int age;
};
int main()
{
int n,m,i,j;
printf("Enter the no of events\n");
scanf("%d",&n);
printf("Enter the no of students\n");
scanf("%d",&m);

struct fest event[n][m];

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("Enter student ID\n");
scanf("%s",event[i][j].studentid);
printf("Enter Student name\n");
scanf("%s",event[i][j].name);
printf("Enter Institute name\n");
scanf("%s",event[i][j].institute);
printf("Enter Age\n");
scanf("%d",&event[i][j].age);
}
}
int x;
for(i=0;i<n;i++)
{
printf("student list of which event do you want? :" );
scanf("%d",&x);
for(j=0;j<m;j++)
{
printf("The student id %s\n",event[x-1][j].studentid);
printf("Student Name %s\n",event[x-1][j].name);
printf("InstituteName %s\n",event[x-1][j].institute);
printf("Age %d\n",event[x-1][j].age);
}
}
return 0;
}