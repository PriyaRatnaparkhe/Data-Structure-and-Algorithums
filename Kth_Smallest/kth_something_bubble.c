#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int g,e,f,m;
m=ub-1;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]>x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
return x[(ub+1)-k];
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
printf("Enter a value for k :");
scanf("%d",&k);
printf("Kth smallest number is %d\n",kth_something(x,0,req-1,k));
free(x);
return 0;
}