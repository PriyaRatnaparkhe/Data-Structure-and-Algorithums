#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,e,f,tmpSize,largest;
int *tmp;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++) 
{
if(x[y]>largest)
{
largest=x[y];
}
}
tmpSize=largest+1;
tmp=(int *)malloc(sizeof(int)*tmpSize);
for(y=0;y<tmpSize;y++) 
{
tmp[y]=0;
}
e=0;
while(e<=9)
{
y=x[e];
tmp[y]=tmp[y]+1;
e++;
}
e=0;
f=0;
while(e<tmpSize)
{
if(tmp[e]!=0)
{
while(tmp[e]>0)
{
x[f]=e;
f++;
tmp[e]=tmp[e]-1;
}
}
e++;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
free(tmp);
return 0;
}