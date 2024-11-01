
#include "link_list.h"

LinkList *createLinkList()
{
    LinkList * list = (LinkList*)malloc(sizeof(LinkList));
    if(list == NULL)
    {
        printf("malloc Linklist err\n");
        return NULL;
    }
    list->count = 0;
    list->head.data = 0;
    list->head.next = NULL;
    return list;
}

void releaseLinkList(LinkList *list)
{
    if(list)
    {
        if(list->head.next)
        {
            linknode * tmp =NULL;
            while(list->head.next)
            {
                tmp = list->head.next;
                list->head.next = tmp->next;
                free(tmp);
                --list->count;
            }
        }
        printf("count == %d\n", list->count);
        free(list);
    }
}

int insertLinkList(LinkList *list, int pos, Element e)
{
    if(pos > list->count)
    {
        printf("not insert\n");
        return -1;
    }
    int cnt = -1;
    linknode* p = &list->head;
    while(p && cnt != (pos - 1))
    {
        p = p->next;
        ++cnt;
    }
    linknode * node = (linknode*) malloc(sizeof(linknode));
    node->data = e;
    node->next = p->next;
    p->next = node;
    ++list->count;
    return 0;
}

int delLinkList(LinkList *list, Element e)
{
    linknode * p = &list->head;
    while(p->next && p->next->data != e)
    {
        p = p->next;
    }
    if(p->next)
    {
        linknode * tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        --list->count;
    }
    else
    {
        printf("err del\n");
        return -1;
    }

    return 0;
}

void printfLinkList(LinkList *list)
{
    linknode *p = list->head.next;
    while(p)
    {
        printf("%c\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void orderLinklist(LinkList *list, linknode* e)
{
    linknode * p = &list->head;
    while(p->next && p->next->data < e->data)
    {
        p = p->next;
    }
    linknode * tmp = p->next;
    p->next = e;
    e->next = tmp;
}

linknode *createLinknode(Element e)
{
    linknode * node = (linknode*)malloc(sizeof (linknode));
    node->next = NULL;
    node->data = e;
    return node;
}
