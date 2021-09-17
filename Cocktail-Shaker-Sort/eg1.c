#include<stdio.h>
int main()
{
int y,x[10],lb,ub,e,g,swapCount=0;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
while(1)
{
swapCount=0;
e=lb;
while(e<ub)
{
if(x[e+1]<x[e])
{
g=x[e];
x[e]=x[e+1];
x[e+1]=g;
swapCount=1;
}
e=e+1;
}
ub=ub-1;
if(swapCount==0) break;
e=ub;
while(e>lb)
{
if(x[e]<x[e-1])
{
g=x[e];
x[e]=x[e-1];
x[e-1]=g;
swapCount=1;
}
e=e-1;
}
if(swapCount==0) break;
lb=lb+1;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}