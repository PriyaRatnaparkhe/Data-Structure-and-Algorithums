#include<stdio.h>
int main()
{
int x[10],y,j,g;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
j=0;
while(j<=9)
{
if(j==0) j=j+1;
if(x[j]<x[j-1])
{
g=x[j-1];
x[j-1]=x[j];
x[j]=g;
j--;
}
else j++;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}