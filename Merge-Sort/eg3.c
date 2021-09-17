#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct to represent StackNode
typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;

//struct to represent Stack(Top-->The header)
typedef struct __stack
{
StackNode *top;
int elementSize;
int size;
}Stack;

// set stack property elementSize as elementSize , size as 0 and top as NULL
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
}

// logic to push and return 0 , if unable to push for whatever reason
// return 1 if successfully pushed
int push(Stack *stack,void *ptr)
{
StackNode *node;
if(stack==NULL) return 0;
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL) return 0; // unable to allocate memory 
if(ptr!=NULL)
{
node->ptr=(void *)malloc(sizeof(stack->elementSize));
if(node->ptr==NULL)
{
free(node);
return 0; 
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
return 1;
}

// pick from stack and place against the block to which ptr pointer is poiniting 
// return 1 if popped
// return 0 if unable to pop
int pop(Stack *stack,void *ptr)
{
int j;
StackNode *node;
if(stack==NULL) return 0;
if(stack->top==NULL) return 0;
if(stack->top->ptr==NULL) 
{
// ptr jisko point kr rha usko null assign karna h 
//*ptr=NULL;
for(j=0;j<stack->elementSize;j++)
{
// sare memory blocks me as a char  0 rakhwa rahe
*(char*)(ptr+j)=(char)0;
}
}
else
{
memcpy(ptr,(const void *)stack->top->ptr,stack->elementSize);
}
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
stack->size--;
return 1;
}

int isEmpty(Stack *stack)
{
if(stack==NULL) return 1; // returning true because stack is empty
if(stack->size==0) return 1;
return 0;
}
// This is a rough idea and will surely fail after a certain point but for now its okk !!
// Code to merge sorted arrays
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int i1,i2,i3,mid;
int size1,size2,size3;
int *tmp;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
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
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
// copy back in x;
i1=lb1;
i3=0;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i3++;
i2++;
}
free(tmp);
}

// Code to maintain Stack and generate series
void mergeSort(int *x,int lowerBound,int upperBound)
{
int mid;
struct LBUB
{
int lb,ub;
};
// element size ke taur pe 8 pass kr rhe
int a,b;
Stack stack1;
Stack stack2;
initStack(&stack1,sizeof(struct LBUB));
initStack(&stack2,sizeof(struct LBUB));
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub);
while(!isEmpty(&stack1))
{
pop(&stack1,(void *)&lbub);
push(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void*)&lbub);
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void*)&lbub);
}
}
while(!isEmpty(&stack2))
{
pop(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,a,mid,mid+1,b);
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
mergeSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}