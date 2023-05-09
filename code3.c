/*
Consider an array A[0, . . . , n − 1] of n integers. Define a peak of A to be an index i with 0 ≤ i < n such
that A[i − 1] < A[i] and A[i] > A[i + 1], where we imagine A[−1] = A[n] = inf. In other words, a peak
x is greater than or equal to its neighbors in A , where we treat the first and last elements as having only
one neighbor. Note that A might have multiple peaks . For example, if A = [10, 6, 4, 3, 12, 19, 18] , then A
has two peaks, 10 and 19. Note that the absolute maximum of A is always a peak , but it requires (n) time
to compute. Develop an O(logn) algorithm to find a peak and also the position in the array.
*/

#include<stdio.h>
int main()
{
int n,i;
printf("Enter the size of array\n");
scanf("%d",&n);
int a[n];
printf("Enter the elements of array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("The array is : ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}

printf("\n");
for(i=1;i<(n-1);i++)
{
if(a[i-1]<a[i] && a[i]>a[i+1])
{
printf("Index of local max %d\n",i);
printf("Local max is %d\n",a[i]);
}
}
	
if(a[0]>a[1])
{
printf("Index of the local max is 0");
printf("Local maxi is %d\n",a[0]);
}
	
if(a[n-1]>a[n-2])
{
printf("Index of the local max is %d\n",n-1);
printf("Local maxi is %d\n",a[n-1]);
}
return 0;
}
