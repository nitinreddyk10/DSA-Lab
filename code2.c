/*
Generate input randomly in your array and filled just 2/3 of the array.
1. Insert a new item at the beginning (count the step)
2. Insert an item at the end (count the step)
3. Traverse and print the position, value and address of the array
4. Take the input (the element) from the user and find the (a)Position in the array, (b) Address of the
value in array (c) Print how many comparison is required to find the element.
5. Delete an item from the end. (count the step)
6. Delete an item from the beginning. (count the step)
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,start,end,i,x,count=0;
printf("Enter the size of array\n");
scanf("%d",&n);

int a[n];
for(i=0;i<n*2/3;i++)
{
a[i]=rand();
}

printf("Enter beginning insertion\n");
scanf("%d",&start);
for(i=n-1;i>=0;i--)
{
a[i+1]=a[i];
}
a[0]=start;

printf("Enter ending insertion\n");
scanf("%d",&end);

a[n-1]=end%10;

for(i=0;i<n;i++)
{
printf("%d  ",a[i]);
}


printf("Position,value and address\n");
for(i=0;i<n;i++)
{
printf("Position=%d\n",i+1);
printf("value=%d\n",a[i]);
printf("Address=%d\n",&a[i]);
}

printf("Enter the required element details\n");
scanf("%d",&x);
for(i=0;i<n;i++)
{
count=count+1;
if(x==a[i])
{
printf("Required Position=%d\n",i+1);
printf("Required Address=%d\n",&a[i]);
printf("Comparisions done=%d\n\n",count);
break;
}
}

printf("After last element deletion\n");
a[n-1]=rand();

for(i=0;i<n;i++)
{
printf("%d \n",a[i]);
}

printf("After first element deletion also\n");
for(i=0;i<n;i++)
{
a[i]=a[i+1];
}

for(i=0;i<n;i++)
{
printf("%d \n",a[i]);
}

return 0;
}
