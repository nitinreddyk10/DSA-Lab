/*Take the inputs from the user as 0’s and 1’s in an array, and find the largest subarray which contains equal
no of 0s and 1s. Analyze and write time and space complexity.
Example1:
Input: 1, 0, 1, 1, 1, 0, 0
Output: 1 to 6 (Starting Index to Finishing Index)
Example2:
Input: 0, 0, 1, 1, 0
Output: 0 to 3 or 1 to 4
Example3:
Input: 1, 1, 1, 1
Output: No such array
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,i,j,temp= -1,sum=0,start;
printf("Enter the size of array:\n");
scanf("%d",&n);

int *a=(int*)malloc(sizeof(int)*n);
printf("Enter the array\n");

for(i=0;i<n;i++)
{
scanf("%d",(a+i));
}

for(i=0;i<n;i++){
if(a[i]==0)
sum=-1;
else
sum=1;
for(j=i+1;j<n;j++)
{
if(a[j]==0)
sum=sum-1;
else
sum=sum+1;
if(sum==0 && temp<j-i+1)
{
temp=j-i+1;
start=i;
}
}
}
if(temp==-1)
printf("No subarray");
else
printf("%d-%d\n",start,start+temp-1);
return 0;
}	