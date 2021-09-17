#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int g,e,f;
for(e=0;e<k;e++)
{
for(f=e+1;f<=9;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
return x[k-1];
}
int main()
{
int *x;
int k,req,y;
printf("Enter your requirement :");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter the value for  k:");
scanf("%d",&k);
printf("Kth smallest number is : %d\n",kth_something(x,0,9,k));
free(x);
return 0;
}
