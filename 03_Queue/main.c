
#include "ArrayQueue.h"
#include "LinkQueue.h"
void test01()
{
    ArrayQueue * queue = createArrayQueue();
    if(queue == NULL)
    {
        printf("queue err\n");
        return;
    }
    for(int i = 0; i < N; ++i)
    {
        pushArrayQueue(queue, i + 100);
    }
    Element e;
    while(popArrayQueue(queue, &e) != -1)
    {
        printf("%d\t", e);
    }
    releaseArrayQueue(queue);
}
void test02()
{
    LinkQueue * queue = createLinkQueue();
    if(queue == NULL)
    {
        printf("queue err\n");
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        pushLinkQueue(queue, i + 100);
    }
    Element e;
    while (popLinkQueue(queue, &e) != -1)
    {
        printf("%d\t", e);
    }
    printf("\n");
    releaseLinkQueue(queue);
}
int main()
{
    //test01();
    test02();
    return 0;
}