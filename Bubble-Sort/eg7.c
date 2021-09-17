#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bubbleSort(void *ptr,int size,int cs,int(*p2f)(void *,void *))
{
int e,f,m,weight;
void *a,*b,*c;
c=(void *)malloc(cs);
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*cs);
b=ptr+(e*cs);
weight=p2f(a,b);
if(weight<0)
{
memcpy(c,(const void *)a,cs);
memcpy(a,(const void *)b,cs);
memcpy(b,(const void *)c,cs);
}
e++;
f++;
}
m--;
}
free(c);
}


struct Student
{
int rollNumber;
char name[21];
};
int studentComparator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
return strcmp(s1->name,s2->name);
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
printf("Unable to allocate memory for %d\n",req);
return 0;
}
j=s;
for(y=0;y<req;y++)
{
printf("Enter Roll Number :");
scanf("%d",&(j->rollNumber));
printf("Enter Name :");
scanf("%s",j->name);
j++;
}
bubbleSort(s,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("%d %s \n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}