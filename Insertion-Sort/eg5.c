#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return (*a)-(*b);
}
int main()
{
int *x,req,y;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement ");
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
insertionSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
void insertionSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
block=(void*)malloc(es);
y=0;
ep=cs-1;
while(y<=ep)
{
memcpy(block,(const void *)(x+(y*es)),es);
z=y-1;
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}