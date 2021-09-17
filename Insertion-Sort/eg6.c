#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int start , int end ,int es,int(*p2f)(void *,void *));
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return (*a)-(*b);
}
int main()
{
int *x,req,y,start,end;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement ");
return 0;
}
printf("Enter start point :");
scanf("%d",&start);
if(start<0 || start>=req)
{
printf("Invalid start point %d in case of collection of numbers %d",start,req);
return 0;
}
printf("Enter end point :");
scanf("%d",&end);
if(end<start || end>=req)
{
printf("Invalid end point %d in case of start point be %d and collection of numbers %d",end,start,req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers \n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
insertionSort(x,start,end,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
void insertionSort(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,z;
void *block;
block=(void*)malloc(es);
y=lb+1;
while(y<=ub)
{
memcpy(block,(const void *)(x+(y*es)),es);
z=y-1;
while(z>=lb && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}