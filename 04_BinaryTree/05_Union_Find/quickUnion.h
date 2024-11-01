#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DS_QUICKUNION_H
#define DS_QUICKUNION_H

typedef char value_t;

typedef struct
{
    value_t *data;   // 数据
    int n;          // 限制
    int capacity;   // 最大容量
    int *parent;    // 父亲节点
    int *size;      // 以本节点为根节点所挂载的子节点数
}QuickUnionSet;

QuickUnionSet* createQuickUnionSet(int capacity);
void releaseQuickUnionSet(QuickUnionSet* QUset);

void initQuickUnionSet(QuickUnionSet* QFset, value_t * data, int n);
// 合并
void unionQuickUnionSet(QuickUnionSet* QFset, value_t a, value_t b);
// 查找是否相同
int isSameQuickUnionSet(QuickUnionSet* QFset, value_t a, value_t b);



// 路径压缩专用
typedef struct _node
{
    int index;      // 对应的下标
    struct _node* next;

}Node;

#endif //DS_QUICKUNION_H
