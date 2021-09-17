#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int cs,int es,int(*p2f)(void *,void *));
struct Student
{
int rollNumber;
char name[21];
};
int myComparator(void *left,void *right)
{
struct Student *a,*b;
a=(struct Student*)left;
b=(struct Student *)right;
return a->rollNumber-b->rollNumber;
}
int main()
{
struct Student *s,*j;
int req,y;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement ");
return 0;
}
s=(struct Student *)malloc(sizeof(struct Student)*req);
if(s==NULL)
{
printf("Unable to allocate memory for %d structures\n",req);
return 0;
}
j=s;
for(y=0;y<req;y++)
{
printf("Enter roll number :");
scanf("%d",&(j->rollNumber));
printf("Enter name :");
scanf("%s",j->name);
j++;
}
insertionSort(s,req,sizeof(struct Student),myComparator);
for(y=0;y<req;y++)
{
printf("%d  %s \n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}
void insertionSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
block=(void*)malloc(es);
y=0;
ep=cs-1;
while(y<=ep)
{
memcpy(block,(const void *)(x+(y*es)),es);
z=y-1;
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}