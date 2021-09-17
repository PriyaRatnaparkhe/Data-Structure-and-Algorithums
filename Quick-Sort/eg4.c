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
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
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
int main()
{
int *x,y,req;
top=NULL;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers \n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}