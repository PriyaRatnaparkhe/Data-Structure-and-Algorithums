#include<stdio.h>
void selectionSort(int *x,int size);
int main()
{
int x[5],y;
y=0;
while(y<=4)
{
printf("Enter a number :");
scanf("%d",&x[y]);
y++;
}
selectionSort(x,5);
y=0;
while(y<=4)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}

void selectionSort(int *x,int size)
{
int e,f,g,si,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
f=e+1;
si=e;
while(f<=iep)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[e];
x[e]=x[si];
x[si]=g;
e++;
}
}