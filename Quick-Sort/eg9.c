#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
int elementSize;
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void push(Stack *stack,const void *data)
{
StackNode *t;
t=(StackNode*)malloc(sizeof(StackNode));
t->data=(void *)malloc(sizeof(stack->elementSize));
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}
void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void *)t->data,stack->elementSize);
free(t->data);
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
void quickSort(void *x,int es,int lb,int ub,int(*p2f)(void *,void *))
{
int lowerBound,upperBound,pp;
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
Stack stk;
initStack(&stk,sizeof(struct LBUB));
lbub.lb=lb;
lbub.ub=ub;
push(&stk,&lbub);
while(!isEmpty(&stk))
{
pop(&stk,&lbub);
printf("%d %d \n",lbub.lb,lbub.ub);
lowerBound=lbub.lb;
upperBound=lbub.ub;
pp=findPartitionPoint(x,lowerBound,upperBound,es,p2f);
if(pp+1<upperBound) 
{
lbub.lb=pp+1;
lbub.ub=upperBound;
push(&stk,&lbub);
}
if(lowerBound<pp-1)
{
lbub.lb=lowerBound;
lbub.ub=pp-1;
push(&stk,&lbub);
}
}
}
int main()
{
int *x,y,req;
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
quickSort((void *)x,sizeof(int),0,req-1,myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
