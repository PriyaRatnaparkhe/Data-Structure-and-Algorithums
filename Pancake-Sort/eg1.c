#include<stdio.h>
int main()
{
int x[10],y,i,lb,ub,size,indexOfLargest,g;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
size=(ub-lb)+1;
while(size>0)
{
lb=0;
ub=size-1;
indexOfLargest=0;
for(y=1;y<=ub;y++)
{
if(x[y]>x[indexOfLargest]) indexOfLargest=y;
}
if(indexOfLargest==ub)
{
size--;
continue;
}
for(i=indexOfLargest,y=0;y<=i;y++,i--)
{
g=x[i];
x[i]=x[y];
x[y]=g;
}
for(i=ub,y=0;y<=i;y++,i--)
{
g=x[i];
x[i]=x[y];
x[y]=g;
}
size--;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}