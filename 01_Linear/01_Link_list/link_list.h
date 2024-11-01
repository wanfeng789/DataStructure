#include <stdio.h>


#ifndef DS_LINK_LIST_H
#define DS_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Element;
// 链表的头结点
typedef struct _linknode
{
    Element data;
    struct _linknode* next;

}linknode;
// 头节点的链表
typedef struct
{
    linknode head;
    int count;
}LinkList;

LinkList * createLinkList();
void releaseLinkList(LinkList* list);
int insertLinkList(LinkList* list, int pos, Element e);
int delLinkList(LinkList* list, Element e);
void printfLinkList(LinkList* list);
void orderLinklist(LinkList* list, linknode *e);
linknode *createLinknode(Element e);
#endif //DS_LINK_LIST_H
