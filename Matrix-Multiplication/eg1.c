#include<stdio.h>
int main()
{
int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int B[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int C[4][4];
int e,f,g,num=0;
for(e=0;e<=3;e++)
{
for(f=0;f<=3;f++)
{
num=0;
for(g=0;g<=3;g++)
{
num=num+A[e][g]*B[g][f];
}
C[e][f]=num;
}
}
printf("     ");
for(e=0;e<=3;e++)
{
printf("%5d ",e);
}
printf("\n");
for(e=0;e<=3;e++)
{
printf("%5d",e);
for(f=0;f<=3;f++)
{
printf("%5d ",C[e][f]);
}
printf("\n");
}
return 0;
}