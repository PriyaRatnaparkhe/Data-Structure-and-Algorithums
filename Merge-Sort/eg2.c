#include<stdio.h>
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
}
void mergeSort(int *x,int lowerBound,int upperBound)
{
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
mergeSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}