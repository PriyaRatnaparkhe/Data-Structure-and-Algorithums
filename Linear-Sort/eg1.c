#include<stdio.h>
int main()
{
int x[10],y,e,f,g,size,oep,iep;
size=10;
for(y=0;y<size;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
for(y=0;y<size;y++)
{
printf("%d\n",x[y]);
}
return 0;
}