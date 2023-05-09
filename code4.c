/*Consider a sorted array A[0, . . . , n − 1]. nd Take input from user (r) arotate either left or right (where r
represent the number of rotation). After rotation, find the minimum element in it. Assume all elements
are distinct. Write recursive program and also the complexity of your program*/

#include <stdio.h>
void rotate1(int n,int arr[])
{
int i;
int last=arr[n-1];
for(i=n-2;i>=0;i--)
{
arr[i+1]=arr[i];
}
arr[0]=last;
}
void rotate2(int n,int arr[],int r)
{
if(r<0||r>=n)
{
return;
}
for(i=0;i<r;i++)
{
rotate1(n,arr);
}
}
int main()
{
int k;
printf ("Enter total number elements:\n");
scanf("%d",&k);
int arr[k];
printf("Enter array elements\n ");
for(i=0;i<k;i++)
{
scanf("%d",&arr[i]);
}
int r;
printf ("Number of rotation??\n");
scanf("%d",&r);
int n=sizeof(arr)/sizeof(arr[0]);
rotate2(n,arr,r);
for(int i=0;i<n;i++)
{
printf("%d",arr[i]);
}
int min=arr[0],i;
for(int i=0;i<n;++i)
{
if(arr[i]<min)
{
min=arr[i];
}
}
printf("Minimum element : %d ",min);
return 0;
}
