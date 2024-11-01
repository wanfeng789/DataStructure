#include "link_list.h"

void test01()
{
    LinkList * list = createLinkList();
    for(int i = 0; i < 5; ++i)
    {
        insertLinkList(list, 0, 'a' + i);
    }
    printfLinkList(list);
    insertLinkList(list, 3, 'f');
    delLinkList(list, 'A');
    releaseLinkList(list);
}
void test02()
{
    LinkList * list = createLinkList();
    linknode * node1 = createLinknode('g');
    linknode * node2 = createLinknode('f');
    linknode * node3 = createLinknode('k');
    linknode * node4 = createLinknode('d');
    linknode * node5 = createLinknode('s');
    linknode * node6 = createLinknode('a');
    list->head.next = node1;
    orderLinklist(list, node3);
    orderLinklist(list, node2);
    orderLinklist(list, node5);
    orderLinklist(list, node6);
    orderLinklist(list, node4);
    printfLinkList(list);
}
int main()
{
    test02();
    return 0;
}
