//
// Created by 晚风 on 2024/9/3.
//

#include "Linkstack.h"

Linkstack *createLinkstack()
{
    Linkstack * stack = (Linkstack*)malloc(sizeof(Linkstack));
    if(stack == NULL)
    {
        perror("malloc Linkstack");
        return NULL;
    }
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

void releaseLinkstack(Linkstack *stack)
{
    if(stack)
    {
        while(stack->top)
        {
            Stacknode * tmp = stack->top;
            stack->top = tmp->next;
            free(tmp);
            --stack->count;
        }
        printf("count = %d\n", stack->count);
        free(stack);
    }
}

void pushLinkstack(Linkstack *stack, Element e)
{
    Stacknode * node = (Stacknode*)malloc(sizeof(Stacknode));
    if(node == NULL)
    {
        perror("malloc Stacknode");
        return;
    }
    node->data = e;
    node->next = stack->top;
    stack->top = node;
    ++stack->count;
}

int popLinkstack(Linkstack *stack, Element *e)
{
    if(stack->top == NULL)
    {
        printf("no element\n");
        return -1;
    }
    *e = stack->top->data;
    Stacknode * tmp = stack->top;
    stack->top = tmp->next;
    free(tmp);
    --stack->count;
    return 0;
}

int TraverseStack(Linkstack *stack)
{
    Stacknode * tmp = NULL;
    Stacknode * node = stack->top;
    while(node)
    {
       tmp = node;
       node = node->next;
       printf("%d\t", tmp->data);
    }
    printf("\n");
    return 0;
}
