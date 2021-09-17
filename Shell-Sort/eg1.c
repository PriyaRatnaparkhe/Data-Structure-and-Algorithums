#include<stdio.h>
int main()
{
int x[10],y,z,num,diff,size,lb,ub;
for(y=0;y<=9;y++)
{
printf("Enter a number:");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
size=(ub-lb)+1;
diff=size/2;
while(diff>=1)
{
y=lb+diff;
while(y<=ub)
{
num=x[y];
z=y-diff;
while(z>=0 && x[z]>num)
{
x[z+diff]=x[z];
z=z-diff;
}
x[z+diff]=num;
y=y+diff;
}
diff=diff/2;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}