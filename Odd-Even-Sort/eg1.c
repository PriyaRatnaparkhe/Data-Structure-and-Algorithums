#include<stdio.h>
int main()
{
int g,swap=0,i,j,x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
while(1)
{
swap=0;
i=1;
j=i+1;
while(i<=7)
{
if(x[j]<x[i])
{
g=x[i];
x[i]=x[j];
x[j]=g;
swap++;
}
i+=2;
j+=2;
}
i=0;
j=i+1;
while(i<=8)
{
if(x[j]<x[i])
{
g=x[i];
x[i]=x[j];
x[j]=g;
swap++;
}
i+=2;
j+=2;
}
if(swap==0) break;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}