#include<stdio.h>
int main()
{
int x[10],y,e,si,f,mid,ei,num;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
e=0;
while(e<=8)
{
si=0;
ei=e;
f=e+1;
num=x[f];
while(si<=ei)
{
mid=si+(ei-si)/2;
if(num==x[mid]) 
{
si=mid;
break;
}
if(num<x[mid]) ei=mid-1;
else si=mid+1;
}
for(y=f;y>si;y--)
{
x[y]=x[y-1];
}
x[si]=num;
e=e+1;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}