#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *ptr,int size,int es,int (*p2f)(void *,void *));
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main()
{
int *x,y,req;
printf("Enter a requirement :");
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
selectionSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
void selectionSort(void *ptr,int cs,int es, int (*p2f)(void *,void *))
{
int e,f,si,oep,iep,weight;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
weight=p2f(a,b);
if(weight<0)
{
si=f;
}
f++;
}
a=ptr+(si*es);
b=ptr+(e*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
}