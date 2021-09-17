#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESSFUL 1
#define FAILED 0
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
void initStack(Stack *stack,int elementSize,int *successful,int *error)
{
if(successful!=NULL) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
return ;
}
if(elementSize<=0)
{
if(error) *error=2;
return;
}
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
if(successful) *successful=SUCCESSFUL;
}

void push(Stack *stack,void *ptr,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL) 
{
if(error) *error=1;
return ; 
}
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL) 
{
// unable to allocate memory 
if(error) *error=3;
return ;
}
if(ptr!=NULL)
{
node->ptr=(void *)malloc(sizeof(stack->elementSize));
if(node->ptr==NULL)
{
free(node);
if(error) *error=3;
return ;
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
if(successful) *successful=SUCCESSFUL;
}

// pick from stack and place against the block to which ptr pointer is poiniting 
void pop(Stack *stack,void *ptr,int *successful,int *error)
{
int j;
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL || ptr==NULL) 
{
if(error) *error=1;
return ;
}
if(stack->top==NULL) 
{
if(error) *error=4;
return ;
}
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
if(successful) *successful=SUCCESSFUL;
}
int isEmpty(Stack *stack,int *successful,int *error)
{
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL) 
{
if(error) *error=1;
return 1; // returning true because stack is empty
}
if(successful) *successful=SUCCESSFUL;
if(stack->size==0) return 1;
return 0;
}
void clearStack(Stack *stack,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
return ;
}
while(stack->top!=NULL)
{
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
}
stack->size=0;
if(successful) *successful=SUCCESSFUL;
}

// Code to merge sorted arrays
void merge(void *x,int(*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error)
{
int i1,i2,i3,mid;
int size1,size2,size3;
void *tmp;
if(successful) *successful=FAILED;
if(error) *error=0;
if(x==NULL || p2f==NULL)
{
if(error) *error=1;
return;
}
if(es<=0)
{
if(error) *error=2;
return ;
}
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(void*)malloc(es*size3);
if(tmp==NULL)
{
if(error) *error=3;
return ; 
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
//if(x[i1]<x[i2])
if(p2f(x+(i1*es),x+(i2*es))<0)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
// copy back in x;
i1=lb1;
i3=0;
while(i1<=ub1)
{
//x[i1]=tmp[i3];
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
//x[i2]=tmp[i3];
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i3++;
i2++;
}
free(tmp);
if(successful) *successful=SUCCESSFUL;
}

// Code to maintain Stack and generate series
void mergeSort(void *x,int(*p2f)(void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error)
{
int mid;
struct LBUB
{
int lb,ub;
};
// element size ke taur pe 8 pass kr rhe
int a,b;
int isSuccessful,errorNumber;
Stack stack1;
Stack stack2;
if(successful) *successful=FAILED;
if(error) *error=0;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
// errorNumber set kiya h parameter variable error ke against
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return; 
}


while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
// No verification or validation needed
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
// Some code required because At some point push may fail 
// Code to clear stack is also needed
//so stack mepehele se jitne elements push ho chuke h wo memory leak ka bahut bada issue hoga
// to before returning from here in case of failure we need to clear stack2 and stack1 
// Clear stack name ka function badhana hoga  

if(!isSuccessful)
{
// errorNumber set kiya h parameter variable error ke against
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return; 
}

a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void*)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
// errorNumber set kiya h parameter variable error ke against
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return; 
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void*)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
// errorNumber set kiya h parameter variable error ke against
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return; 
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
// errorNumber set kiya h parameter variable error ke against
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return; 
}
}
if(successful) *successful=SUCCESSFUL;
}
int intComparator(void*left,void *right)
{
return (*((int *)left))-(*((int*)right));
}
int main()
{
int isSuccessful,errorNumber;
int *x,y,req;
printf("Enter requirement :");
scanf("%d",&req);
if(req<=0) 
{
printf("Invalid requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Invalid Requirement,  Unable to allocate memory for %d numbers \n",req);
return 0;
}
/*for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}*/
// Garbage value gets sorted and printed
mergeSort((void*)x,intComparator,sizeof(int),0,req-1,&isSuccessful,&errorNumber);
for(y=0;y<req;y++)
{
printf("%d %d\n",y,x[y]);
}
return 0;
}