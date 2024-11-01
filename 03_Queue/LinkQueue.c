

#include "LinkQueue.h"

LinkQueue *createLinkQueue()
{
    LinkQueue * queue = (LinkQueue*) malloc(sizeof(LinkQueue));
    if(queue == NULL)
    {
        printf("queue malloc err\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    queue->count = 0;
    return queue;
}

void releaseLinkQueue(LinkQueue *queue)
{
    if(queue)
    {
        QueueNode * tmp = NULL;
        while(queue->front)
        {
             tmp = queue->front;
            queue->front = tmp->next;
            free(tmp);
            --queue->count;
        }
        printf("count = %d\n", queue->count);
        free(queue);
    }


}

int pushLinkQueue(LinkQueue *queue, Element e)
{
    QueueNode * node = (QueueNode*) malloc(sizeof(QueueNode));
    if(node == NULL)
    {
        printf("malloc QueueNode err\n");
        return -1;
    }
    node->next = NULL;
    node->data = e;
    if(queue->rear)
    {
        queue->rear->next = node;
    }
    else
    {
        queue->front = node;
    }
    queue->rear = node;
    ++queue->count;
    return 0;
}

int popLinkQueue(LinkQueue *queue, Element *e)
{
    if(queue->front == NULL)
    {
        printf("empty element\n");
        return -1;
    }
    *e = queue->front->data;
    QueueNode * tmp = queue->front;
    queue->front = tmp->next;
    free(tmp);
    --queue->count;
    // 没有元素了那么  尾指针就没意义了
    if(queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return 0;
}
