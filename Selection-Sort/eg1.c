#include<stdio.h>
int main()
{
int x[10],y,e,f,g,si;
y=0;
while(y<=9)
{
printf("Enter a number :");
scanf("%d",&x[y]);
y++;
}
e=0;
while(e<=8)
{
si=e;
f=e+1;
while(f<=9)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
y=0;
while(y<=9)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}