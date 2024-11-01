
#include <stdio.h>
#include <stdlib.h>
/*
 *      不带头节点的循环链表
 */
typedef int Element;
typedef struct _node
{
    Element val;
    struct _node* next;
}Node;
typedef struct
{
    Node * head;    // 头指针
    Node* tail;     // 尾指针
}Joseph;
// 初始化约瑟夫环
void initJoseph(Joseph *joseph, int n)
{
    Node* node = NULL;
    for(int i = 1; i <= n; ++i)
    {
        node = (Node*)malloc(sizeof(Node));
        node->val = i;
        node->next = NULL;
        if(joseph->head == NULL)
        {
            joseph->head = joseph->tail = node;
        }
        else
        {
            joseph->tail->next = node;
            joseph->tail = node;
        }
    }
    // 最后构成闭环
    joseph->tail->next = joseph->head;
}
void showJoseph(Joseph* joseph)
{
    Node * p = joseph->head;
    do
    {
        printf("%d\t", p->val);
        p = p->next;
    }while(p != joseph->head);
}
void startGameJoseph(Joseph* joseph, int n)
{
    Node * front = NULL;
    Node* rear = joseph->head;
    while(rear->next != rear)
    {
        for (int i = 1; i < n; ++i) {
            front = rear;
            rear = rear->next;
        }
        front->next = rear->next;
        printf("%d\t", rear->val);
        free(rear);
        rear = front->next;
    }
    printf("\nlast people: %d\n", rear->val);
}
void test01()
{
    Joseph joseph = {NULL, NULL};
    initJoseph(&joseph, 10);
    showJoseph(&joseph);
    printf("\n");
    startGameJoseph(&joseph, 3);
}
int main()
{
    test01();


    return 0;
}



