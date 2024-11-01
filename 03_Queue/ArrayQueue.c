
#include "ArrayQueue.h"

ArrayQueue *createArrayQueue()
{
    ArrayQueue * queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if(queue == NULL)
    {
        printf("malloc err\n");
        return NULL;
    }
    memset(queue->data, 0, sizeof(queue->data));
    queue->rear = queue->front = 0;
    return queue;
}

int releaseArrayQueue(ArrayQueue *queue)
{
    if(queue)
    {
        free(queue);
    }
    return 0;
}

int pushArrayQueue(ArrayQueue *queue, Element e)
{
    // 判断头指针和 尾指针 + 1有没有重叠
    if(((queue->rear + 1) % N) == queue->front)
    {
        printf("full element\n");
        return -1;
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % N;

    return 0;
}

int popArrayQueue(ArrayQueue *queue, Element *e)
{
    if(queue->rear == queue->front)
    {
        printf("empty element\n");
        return -1;
    }
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % N;
    return 0;
}
