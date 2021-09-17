#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int size,int es,int(*p2f)(void *,void *))
{
int e,f,oep,iep,weight;
void *a,*b,*c;
c=(void *)malloc(es);
oep=size-2;
iep=size-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
weight=p2f(a,b);
if(weight<=0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}


int myComparator(void *left , void *right)
{
int *a1,*a2;
a1=(int *)left;
a2=(int *)right;
return (*a1)-(*a2);
}
int main()
{
int *x,y,req;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement ");
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
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}