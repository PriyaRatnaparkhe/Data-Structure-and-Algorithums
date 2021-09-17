#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dcLargest=0;
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;

void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}

void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}

int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
return num;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}
int hash(int num)
{
int dc;
dc=1;
while(num>9)
{
num=num/10;
dc++;
}
if(dc==dcLargest)
{
while(num>=10) num=num/10;
}
else num=0;
return num;
}
void sort(int *x,int lb,int ub)
{
Queue queues[10];
QueueNode *currentNode,*nextNode;
int y,g,i,largest,dc,num,index;
for(y=0;y<=9;y++)
{
initQueue(&queues[y]);
}
largest=x[lb];
for(y=1;y<=ub;y++)
{
if(x[y]>largest) largest=x[y];
}
num=largest;
dc=1;
while(num>9)
{
num=num/10;
dc++;
}
dcLargest=dc;
for(y=0;y<=ub;y++)
{
index=hash(x[y]);
addToQueue(&queues[index],x[y]);
if(queues[index].size>1)
{
currentNode=queues[index].start;
while(currentNode!=NULL)
{
nextNode=currentNode->next;
while(nextNode!=NULL)
{
if(currentNode->num>nextNode->num)
{
g=currentNode->num;
currentNode->num=nextNode->num;
nextNode->num=g;
}
nextNode=nextNode->next;
}
currentNode=currentNode->next;
}
}
}
i=0;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num;
i++;
}
y++;
}
for(y=0;y<=9;y++)
{
clearQueue(&queues[y]);
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
sort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}