#include<stdio.h>
#include<stdlib.h>
int kth_something(int *x,int lb,int ub,int k)
{
int y,rr,ci,ri,lci,rci,swi,g;
y=lb+1;
while(y<k)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ri]<x[ci])
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
rr=k;
while(rr<=ub)
{
if(x[rr]<x[0])
{
g=x[rr];
x[rr]=x[0];
x[0]=g;
ri=0;
while(ri<k)
{
lci=ri*2+1;
if(lci>=k)
{
break;
}
rci=lci+1;
if(rci>=k)
{
swi=lci;
}
else
{
if(x[lci]>x[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
if(x[swi]>x[ri])
{
g=x[ri];
x[ri]=x[swi];
x[swi]=g;
ri=swi;
}
else
{
break;
}
}
}
rr++;
}
return x[0];
}
int main()
{
int *x;
int y,k,req;
printf("Enter your requirement :");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter the value of k:");
scanf("%d",&k);
printf("kth smallest value is %d\n",kth_something(x,0,req-1,k));
free(x);
return 0;
}