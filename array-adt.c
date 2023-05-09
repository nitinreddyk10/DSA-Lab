#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int totsize;
    int usedsize;
    int*ptr;
};

void createarr(struct myarray*a,int tsize,int usize)
{
    //(*a).totsize=tsize;
    //(*a).usedsize=usize;
    //(*a).ptr=(int*)malloc(tsize*sizeof(int));

    a->totsize=tsize;
    a->usedsize=usize;
    a->ptr=(int*)malloc(tsize*sizeof(int));
}

void show(struct myarray*a)
{
    for(int i=0;i<a->usedsize;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void setval(struct myarray*a)
{
    for(int i=0;i<a->usedsize;i++)
    {
        int n;
        printf("enter element %d\n",i);
        scanf("%d\n",&n);
        (a->ptr)[i]=n;
    }
}

int main()
{
    struct myarray marks;
    createarr(&marks,10,2);/*tot 10 atudents,currently 2 students details are there*/

    printf("We are running setval now\n");
    setval(&marks);
    printf("We are running show now\n");
    show(&marks);
}