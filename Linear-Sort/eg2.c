#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x,y,req,e,f,g,oep,iep;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement ");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers ",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
oep=req-2;
iep=req-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}