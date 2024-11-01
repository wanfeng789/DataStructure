

#ifndef DS_LINKSTACK_H
#define DS_LINKSTACK_H
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
// 栈中元素
typedef struct _stack_node
{
    Element data;
    struct _stack_node* next;
}Stacknode;

typedef struct
{
    Stacknode * top;
    int count;
}Linkstack;

Linkstack * createLinkstack();
void releaseLinkstack(Linkstack* stack);
void pushLinkstack(Linkstack* stack, Element e);
int popLinkstack(Linkstack* stack, Element* e);



int TraverseStack(Linkstack* stack);
#endif //DS_LINKSTACK_H
