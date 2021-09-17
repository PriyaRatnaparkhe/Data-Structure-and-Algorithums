#include<stdio.h>
#include<stdlib.h>
int getPP(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])
{
e=e+1;
}
while(x[f]>x[lb])
{
f=f-1;
}
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
}
}
return f;
}
void quickSort(int *x, int lowerbound,int upperbound)
{
int lb,ub,lowerBound,upperBound,size,top,pp;
int *lbstack , *ubstack;
size=(upperbound-lowerbound)+1;
lbstack=(int *)malloc(sizeof(int)*size);
ubstack=(int *)malloc(sizeof(int)*size);
if(lbstack==NULL || ubstack==NULL)
{
printf("Unable to sort %d numbers \n",size);
return;
}
lowerBound=lowerbound;
upperBound=upperbound;
top=size;
top--;
lbstack[top]=lowerBound;
ubstack[top]=upperBound;
while(top!=size)
{
lb=lbstack[top];
ub=ubstack[top];
top++;
pp=getPP(x,lb,ub);
if(pp+1<ub)
{
top--;
lbstack[top]=pp+1;
ubstack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbstack[top]=lb;
ubstack[top]=pp-1;
}
}
free(lbstack);
free(ubstack);
}
int main()
{
int *x,req,y;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers \n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}