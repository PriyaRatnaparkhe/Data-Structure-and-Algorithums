#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
}Stack;
void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void push(Stack *stack,int data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=data;
t->next=stack->top;
stack->top=t;
stack->size++;
}
int pop(Stack *stack)
{
int data;
StackNode *t;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
free(t);
return data;
}
int findPartitionPoint(int *x, int lowerBound,int upperBound)
{
int g,e,f,pp,lb,ub;
lb=lowerBound;
ub=upperBound;
e=lb;
f=ub;
while(e<f)
{
while(e<ub &&x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
Stack lbstack,ubstack;
int lb,ub,pp;
initStack(&lbstack);
initStack(&ubstack);
push(&lbstack,lowerBound);
push(&ubstack,upperBound);
while(!isEmpty(&lbstack))
{
lb=pop(&lbstack);
ub=pop(&ubstack);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
push(&lbstack,pp+1);
push(&ubstack,ub);
}
if(lb<pp-1)
{
push(&lbstack,lb);
push(&ubstack,pp-1);
}
}
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
quickSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}