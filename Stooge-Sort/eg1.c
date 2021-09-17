#include<stdio.h>
void stoogeSort(int *x,int lb,int ub)
{
int size,g,t;
size=(ub-lb)+1;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
if(size>2)
{
t=size/3;
stoogeSort(x,lb,ub-t);
stoogeSort(x,lb+t,ub);
stoogeSort(x,lb,ub-t);
}
}
int main()
{
int x[10],y,lb,ub;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
stoogeSort(x,lb,ub);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}