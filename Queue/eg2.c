#include<stdlib.h>
#include<stdio.h>
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

int main()
{
int num,ch;
Queue queue;
initQueue(&queue);
while(1)
{
printf("1. Add to queue\n");
printf("2. Remove from queue\n");
printf("3. Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter the number you want to add to queue:");
scanf("%d",&num);
addToQueue(&queue,num);
printf("%d added to queue\n",num);
}
if(ch==2)
{
if(isQueueEmpty(&queue)) 
{
printf("Queue is empty\n");
}
else
{
num=removeFromQueue(&queue);
printf("%d removed from queue\n",num);
}
}
if(ch==3) break;
}
clearQueue(&queue);
return 0;
}