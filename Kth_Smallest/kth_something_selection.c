#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int e,si,f,g;
e=0;
while(e<k)
{
si=e;
f=e+1;
while(f<=9)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
return x[k-1];
}
int main()
{
int *x;
int y,req,k;
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
printf("Kth smallest number is %d\n",kth_something(x,0,9,k));
free(x);
return 0;
}