#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int e,f,n,g,swapCount=0;
n=k-1;
while(1)
{
swapCount=0;
e=lb;
while(e<n)
{
if(x[e]>x[n])
{
g=x[e];
x[e]=x[n];
x[n]=g;
swapCount++;
break;
}
e++;
}
f=ub;
while(f>n)
{
if(x[f]<x[n])
{
g=x[f];
x[f]=x[n];
x[n]=g;
swapCount++;
break;
}
f--;
}
if(swapCount==0)
{
break;
}
}
return x[n];
}
int main()
{
int *x;
int req,y,k;
printf("Enter your requirement :");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter the value for k:");
scanf("%d",&k);
printf("kth smallest value is %d\n",kth_something(x,0,req-1,k));
free(x);
return 0;
}