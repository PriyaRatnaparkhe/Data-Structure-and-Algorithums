#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int y,ee,ci,pi,lci,rci,g,swi,ri;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]<x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
y=ub;
ee=lb+1;
while(ee<k)
{
g=x[0];
x[0]=x[y];
x[y]=g;
y--;
ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(x[lci]<x[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
if(x[swi]<x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else
{
break;
}
}
ee++;
}
return x[0];
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
printf("kth smallest number is : %d\n",kth_something(x,0,req-1,k));
free(x);
return 0;
}