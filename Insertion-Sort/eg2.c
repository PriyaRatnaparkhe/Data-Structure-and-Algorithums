#include<stdio.h>
int main()
{
int x[10],y,z,num;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
for(y=1;y<=9;y++)
{
for(num=x[y],z=y-1;z>=0 &&x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}