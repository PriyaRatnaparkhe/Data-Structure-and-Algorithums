#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int size,int es,int(*p2f)(void *,void *))
{
int oep,iep,weight,e,f;
void *a,*b,*c;
c=(void *)malloc(es);
oep=size-2;
iep=size-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
weight=p2f(a,b);
if(weight<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
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
return s1->rollNumber - s2->rollNumber;
}
int main()
{
struct Student *s,*j;
int y,req;
printf("Enter ypur requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement ");
return 0;
}
s=(struct Student *)malloc(sizeof(struct Student )*req);
if(s==NULL)
{
printf("Unable to allocate memory for %d\n",req);
return 0;
}
j=s;
for(y=0;y<req;y++)
{
printf("Enter roll Number :");
scanf("%d",&(j->rollNumber));
printf("Enter name :");
scanf("%s",j->name);
j++;
}
linearSort(s,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("%d %s \n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}