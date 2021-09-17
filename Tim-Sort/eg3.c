#include<stdio.h>
void insertionSort(int *x,int lb,int ub)
{
int ep,y,z,num;
ep=ub;
for(y=lb+1;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=lb &&x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}
}
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int tmp[216];
int lb3,ub3,i1,i2,i3;
lb3=lb1;
ub3=ub2;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=lb3;
while(i3<=ub3)
{
x[i3]=tmp[i3];
i3++;
}
}
int main()
{
int x[216],y,chunkSize=16,totalRead=0,totalNumbers=216,num,mid,r,lb,ub;
FILE *f;
f=fopen("data2.d","rb");
y=0;
while(y<216)
{
fread(&num,sizeof(int),1,f);
x[y]=num;
y++;
}
fclose(f);
y=0;
r=0;
lb=0;
ub=chunkSize-1;
while(r<totalNumbers)
{
insertionSort(x,lb,ub);
r=r+chunkSize;
totalRead=totalRead+chunkSize;
if((totalNumbers-totalRead)<chunkSize)
{
chunkSize=totalNumbers-totalRead;
}
lb=ub+1;
ub=ub+chunkSize;
y++;
}
chunkSize=16;
totalNumbers=216;
while(chunkSize<totalNumbers)
{
lb=0;
while(lb<totalNumbers)
{
if(lb+(chunkSize-1)>totalNumbers) 
{
mid=totalNumbers-2;
}
else 
{
mid=lb+(chunkSize-1);
}
if((lb+chunkSize*2)>totalNumbers) 
{
ub=totalNumbers-1;
}
else 
{
ub=lb+(chunkSize*2)-1;
}
merge(x,lb,mid,mid+1,ub);
lb=lb+(chunkSize*2);
}
chunkSize=chunkSize*2;
}
for(y=0;y<216;y++) printf("%d\n",x[y]);
return 0;
}