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
int x[10],y,e,f,i,num,largest,dc,k,yy,ii,rr,rp,pr,flag,parts,lb,ub,tm,g;
Queue queues[10];
for(i=0;i<=9;i++)
{
initQueue(&queues[i]);
}
for(y=0;y<=9;y++)
{
printf("Enter a  number :");
scanf("%d",&x[y]);
}
yy=0;
ii=0;
while(yy<=9)
{
if(x[yy]<0)
{
g=x[ii];
x[ii]=x[yy];
x[yy]=g;
ii++;
}
yy++;
}// All the -ve numbers present will acquire starting indices

//All are positive
if(ii==0)
{
lb=0;
ub=9;
parts=1;
flag=0;
}

// There is only one -ve number
// Due to the working of above loop that number will be at 0 index
if(ii==1)
{
lb=1;
ub=9;
parts=1;
flag=0;
}

if(ii>1)
{
// There are more than one -ve numbers
if(ii==9)
{
// There is only one positive no which will be on index 9
lb=0;
ub=8;
flag=1;
parts=1;
}
if(ii==10)
{
// All the numbers are -ve
lb=0;
ub=9;
parts=1;
flag=1;
}
else
{
lb=0;
ub=ii-1;
parts=2;
flag=1;
}
for(tm=0;tm<=ub;tm++)
{
x[tm]=x[tm]*(-1);
}
}

rr=0;
while(rr<parts)
{
largest=x[lb];
for(y=1;y<=ub;y++)
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
y=lb;
while(y<=ub)
{
num=x[y];
i=(num%e)/f;
// add the num to i th queue
addToQueue(&queues[i],num);
y++;
}
// collect all numbers from 10 queues and keep in array
i=lb;
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
if(flag==1)
{
for(pr=lb,rp=ub;pr<=rp;pr++,rp--)
{
g=x[pr];
x[pr]=x[rp];
x[rp]=g;
}
for(y=0;y<=ub;y++)
{
x[y]=x[y]*(-1);
}
flag=2;
lb=ii;
ub=9;
for(y=0;y<=9;y++) clearQueue(&queues[y]);
}
rr++;
}
for(y=0;y<=9;y++) clearQueue(&queues[y]);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}