#include<stdio.h>
int main()
{
int x[10],y,z,num;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
y=1;
while(y<=9)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}