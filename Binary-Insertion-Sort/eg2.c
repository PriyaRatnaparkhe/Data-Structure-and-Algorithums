#include<stdio.h>
int main()
{
int num,mid,si,ei,x[10],y;
for(y=0;y<=8;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
x[y]=0;
printf("Enter the number you want to insert:");
scanf("%d",&num);
si=0;
ei=9;
while(si<=ei)
{
mid=si+(ei-si)/2;
if(num==x[mid]) break;
if(num<x[mid]) ei=mid-1;
else si=mid+1;
}
for(y=9;y>si;y--)
{
x[y]=x[y-1];
}
x[si]=num;
printf("%d num inserted at index %d\n",num,si);
printf("&&&&&&&&&&&&&&&&&&&&&&\n");
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}