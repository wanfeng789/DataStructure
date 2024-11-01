
#ifndef DS_ARRAYQUEUE_H
#define DS_ARRAYQUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5
typedef int Element;
// 顺序存储队列
typedef struct
{
    Element data[N];
    int front;
    int rear;
}ArrayQueue;

ArrayQueue *createArrayQueue();
int releaseArrayQueue(ArrayQueue* queue);
// 插入元素
int pushArrayQueue(ArrayQueue* queue, Element e);
// 删除元素
int popArrayQueue(ArrayQueue* queue, Element *e);
#endif //DS_ARRAYQUEUE_H
