#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *));
struct Student
{
int rollNumber;
char name[21];
};
int myComparator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
return (s1->rollNumber)-(s2->rollNumber);
}
int main()
{
struct Student *s,*j;
int y,req;
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
printf("Unable to allocate memory for %d structures \n",req);
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
selectionSort(s,req,sizeof(struct Student),myComparator);
for(y=0;y<req;y++)
{
printf("%d %s \n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int oep,iep,weight,e,f,si;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
weight=p2f(a,b);
if(weight<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
}