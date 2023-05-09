/*
For a given array of n integers where assume that ’0’ is an invalid number and all others as a valid number.
Convert the array in such a way that if both current and next element is valid and both have same value
then double current value and replace the next number with 0. After the modification, rearrange the array
such that all 0’s shifted to the end.
Input : arr[] = 2, 2, 0, 4, 0, 8
Output : 4 4 8 0 0 0
Input : arr[] = 0, 2, 2, 2, 0, 6, 6, 0, 0, 8
Output : 4 2 12 8 0 0 0 0 0 0
*/

#include<stdio.h>

int main()
{
int n;
printf("Enter number of elements in array:\n");
scanf("%d",&n);

int i,a[n];
printf("Enter array elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

int count=0;
for(i=0;i<n;i++)
{
if(a[i]==0)
{
count=count+1;
}
if((a[i]!=0 && a[i+1]!=0)&& a[i]==a[i+1])
{
a[i+1]=0;
a[i]=a[i]*2;
count=count+1;
}
}

for(i=0;i<n;i++)
{

}

// printf("count=%d",count); = 4

int j,temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]==0)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}

printf("Final array=");
for(i=0;i<n;i++)
{
printf("%d  ",a[i]);
}
return 0;
}
