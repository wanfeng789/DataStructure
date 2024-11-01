//
// Created by 晚风 on 2024/10/11.
//

#include "quickUnion.h"

QuickUnionSet *createQuickUnionSet(int capacity)
{
    QuickUnionSet * QUset = (QuickUnionSet*) malloc(sizeof(QuickUnionSet));
    QUset->data = (value_t *)malloc(sizeof(value_t) * capacity);
    QUset->parent = (int*) malloc(sizeof(int) * capacity);
    QUset->size = (int*)malloc(sizeof(int) * capacity);
    QUset->capacity = capacity;
    QUset->n = 0;
    return QUset;
}

void releaseQuickUnionSet(QuickUnionSet *QUset)
{
    if(QUset)
    {
        free(QUset->data);
        free(QUset->size);
        free(QUset->parent);
        free(QUset);
    }

}

void initQuickUnionSet(QuickUnionSet *QUset, value_t *data, int n)
{
    for(int i = 0; i < n; ++i)
    {
        QUset->data[i] = data[i];
        QUset->parent[i] = i;
        QUset->size[i] = 1;
    }
    QUset->n = n;
}
static int findIndex(QuickUnionSet* QUset, value_t e)
{
    for(int i = 0; i < QUset->n; ++i)
    {
        if(QUset->data[i] == e)
        {
            return i;
        }
    }
    return -1;
}
/*  路径压缩版和不是路径压缩版
 */

#define PAHT_COMPRESS
#ifndef PAHT_COMPRESS
static int findRootIndex(QuickUnionSet* QUset, value_t e)
{
    int curIndex = findIndex(QUset, e);
    while(QUset->parent[curIndex] != curIndex)
    {
        curIndex = QUset->parent[curIndex];
    }
    return curIndex;
}

#else
static Node* push(Node* top, int index)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->index = index;
    node->next = top;
    return node;
}
static Node* pop(Node* top, int*index)
{
    Node* tmp = top;
    *index = top->index;
    top = top->next;
    free(tmp);
    return top;
}
static int findRootIndex(QuickUnionSet* QUset, value_t e)
{
    Node * root = NULL;
    int curIndex = findIndex(QUset, e);
    while(QUset->parent[curIndex] != curIndex)
    {
        root = push(root, curIndex);
        curIndex = QUset->parent[curIndex];
    }
    while(root)
    {
        int index;
        root = pop(root, &index);
        QUset->parent[index] = curIndex;

    }
    return curIndex;
}

#endif

void unionQuickUnionSet(QuickUnionSet *QUset, value_t a, value_t b)
{
    int aRootIndex = findRootIndex(QUset,a);
    int bRootIndex = findRootIndex(QUset, b);
    if(aRootIndex != bRootIndex)
    {
        int aSize = QUset->size[aRootIndex];
        int bSize = QUset->size[bRootIndex];
        if(aSize >= bSize)
        {
            // 把b的老大换成a
            QUset->parent[bRootIndex] = aRootIndex;
            QUset->size[aRootIndex] += QUset->size[bRootIndex];
        }
        else
        {
            // 把a的老大换成b
            QUset->parent[aRootIndex] = bRootIndex;
            QUset->size[bRootIndex] += QUset->size[aRootIndex];
        }
    }

}

int isSameQuickUnionSet(QuickUnionSet *QUset, value_t a, value_t b)
{
    int aRootIndex = findRootIndex(QUset,a);
    int bRootIndex = findRootIndex(QUset, b);

    return aRootIndex == bRootIndex;
}
