

#ifndef DS_LINKQUEUE_H
#define DS_LINKQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 链式存储队列
typedef int Element;
typedef struct _queue_node
{
    Element data;
    struct _queue_node* next;

}QueueNode;

typedef struct
{
    QueueNode * front;
    QueueNode * rear;
    int count;
}LinkQueue;

LinkQueue *createLinkQueue();
void releaseLinkQueue(LinkQueue* queue);
int pushLinkQueue(LinkQueue * queue, Element e);
int popLinkQueue(LinkQueue * queue, Element *e);
#endif //DS_LINKQUEUE_H
