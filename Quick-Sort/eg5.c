#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node* next;
};
struct Node *top;
int isEmpty()
{
return top==NULL;
}
void push(int lowerBound,int upperBound)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->lb=lowerBound;
t->ub=upperBound;
t->next=top;
top=t;
}
void pop(int *lowerBound,int *upperBound)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
*lowerBound=top->lb;
*upperBound=top->ub;
t=top;
top=top->next;
free(t);
}

int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
//while(e<ub &&x[e]<=x[lb]) e++;
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0) e++;
//while(x[f]>x[lb]) f--;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
//g=x[e];
memcpy(g,(const void *)(x+(e*es)),es);
//x[e]=x[f];
memcpy((x+(e*es)),(const void *)(x+(f*es)),es);
//x[f]=g;
memcpy((x+(f*es)),(const void *)(g),es);
}
else
{
//g=x[lb];
memcpy(g,(const void *)(x+(lb*es)),es);
//x[lb]=x[f];
memcpy((x+(lb*es)),(const void *)(x+(f*es)),es);
//x[f]=g;
memcpy((x+(f*es)),(const void *)(g),es);
}
}
free(g);
return f;
}
void quickSort(void *x,int lowerBound, int upperBound,int es,int (*p2f)(void *,void *))
{
int pp,lb,ub;
push(lowerBound,upperBound);
while(!isEmpty())
{
// control loop me jaega jab stack empty naahi h 
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
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
return s1->rollNumber-s2->rollNumber;
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
quickSort(s,0,req-1,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("%d %s \n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}