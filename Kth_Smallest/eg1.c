#include<stdio.h>
#include<stdlib.h>
void heapSort(int *x,int lb,int ub)
{
int y,ri,ci,lci,rci,g,swi;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
y=ub;
while(y>lb)
{
g=x[lb];
x[lb]=x[y];
x[y]=g;
y--;
ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(x[lci]>x[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else
{
break;
}
}
}
}
int kth_smallest(int *x,int size,int k)
{
heapSort(x,0,size-1);
return x[k-1];
}
int main()
{
int *x;
int size,y,k;
printf("Enter your requirement :");
scanf("%d",&size);
x=(int*)malloc(sizeof(int)*size);
for(y=0;y<size;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter the value of k:");
scanf("%d",&k);
printf("Kth Smallest number is : %d \n",kth_smallest(x,size,k));
free(x);
return 0;
}