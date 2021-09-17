#include<stdio.h>
int main()
{
int x[10]={6,4,12,33,32,176,154,19,27,62};
int e,f,invCount;
invCount=0;
for(e=0;e<=8;e++)
{
for(f=e+1;f<=9;f++)
{
if(x[e]>x[f]) invCount++;
}
}
printf("Inversion count : %d\n",invCount);
return 0;
}
