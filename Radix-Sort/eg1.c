#include<stdlib.h>
#include<stdio.h>
// Queue me jo no add krwana h wo rakhne ke liye
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;

// Header jiske against queue latki hui h 
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

int main()
{
int x[10],y,e,f,i,num,largest,dc,k;
Queue queues[10];
for(i=0;i<=9;i++)
{
initQueue(&queues[i]);
}
// 10 queue structures having places for start , end and size
for(y=0;y<=9;y++)
{
printf("Enter a  number :");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
i=0;
e=10;
f=1;
k=1;
while(k<=dc)
{
// spread out in 10 queues according to digits at kth place (from right side)
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
// add the num to i th queue
addToQueue(&queues[i],num);
y++;
}
// collect all nos from 10 queues and keep in array
i=0;
y=0;
while(y<=9)
{
// remove from yth queue
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num;
i++;
}
y++;
}
f=f*10;
e=e*10;
k++;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}