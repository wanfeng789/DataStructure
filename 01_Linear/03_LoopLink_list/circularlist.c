
#include <stdio.h>
#include <stdlib.h>


typedef int Element;
// 定义节点
typedef struct _node
{
    Element  val;
    struct _node* next;
}Node;

// 定义带头节点的循环链表
typedef struct
{
    Node  head;     // 头节点
    Node * rear;    // 尾差法 提高插入的效率
    int num;        // 记录节点个数
}CircularList;

void init(CircularList* circularList)
{
    circularList->rear = NULL;
    circularList->num = 0;
    circularList->head.val = 0;
    circularList->head.next = &circularList->head;
}
void insertCircularList(CircularList* circularList, Element val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = circularList->head.next;
    circularList->head.next = node;
    if(circularList->rear == NULL)
    {
        circularList->rear = node;
    }
    ++circularList->num;
}
void showCircularList(const CircularList* circularList)
{
    Node * p = circularList->head.next;
    while(p != &circularList->head)
    {
        printf("%d\t", p->val);
        p = p->next;
    }
}
void releaseCircularList(CircularList* circularList)
{
    Node * p = circularList->head.next;
    Node * tmp = NULL;
    while(p != &circularList->head)
    {
       tmp = p;
        p = p->next;
        free(tmp);
        --circularList->num;
    }
}

void test01()
{
    CircularList circularList;
    init(&circularList);
    for(int i = 0; i < 10; ++i)
    {
        insertCircularList(&circularList, i + 100);
    }
    showCircularList(&circularList);
    printf("\n");
    printf("num: %d\n", circularList.num);
    releaseCircularList(&circularList);
    printf("num: %d\n", circularList.num);
}
int main()
{
    test01();

}







