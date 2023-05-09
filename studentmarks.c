/*
In your last course Programming in C, every student got different marks. Read the Student’s roll number
and Marks in an array. Segregate even and odd marks in the array. Print the array which will show all
the students who got even numbers marks first, and then the odd numbers marks. Analyze and print the
Time and Space complexity for your Algorithm.
*/

#include<stdio.h>
struct student
{
char rollno[20];
int marks;
};
int main()
{
int n,i,j;
printf("Enter the no of Students\n");
scanf("%d",&n);
struct student a[n];

for(i=0;i<n;i++)
{
printf("Enter student roll no\n");
scanf("%s",a[i].rollno);
printf("Enter student marks\n");
scanf("%d",&a[i].marks);
}

printf("The even numbered marks student details:\n");

for(i=0;i<n;i++)
{
if(a[i].marks%2==0)
{
printf("The student roll no: %s\n",a[i].rollno);
printf("student marks: %d\n",a[i].marks);
}
}

printf("The odd numbered marks student details:\n");

for(i=0;i<n;i++)
{
if(a[i].marks%2==1){
printf("The student roll no: %s\n",a[i].rollno);
printf("student marks: %d\n",a[i].marks);
}
}
return 0;
}