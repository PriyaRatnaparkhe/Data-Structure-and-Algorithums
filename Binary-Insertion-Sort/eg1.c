#include<stdio.h>
int main()
{
int mid,flag,num,x[10],y,si,ei;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter the number you want to search :");
scanf("%d",&num);
si=0;
ei=9;
while(si<=ei)
{
flag=0;
mid=si+(ei-si)/2;
if(num==x[mid])
{
flag=mid;
break;
}
if(num<x[mid])
{
ei=mid-1;
}
else
{
si=mid+1;
}
}
if(flag==0) printf("Not found\n");
else printf("%d number found out at index %d",num,flag);
return 0;
}