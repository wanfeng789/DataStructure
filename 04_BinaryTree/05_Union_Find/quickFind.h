#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DS_QUICKFIND_H
#define DS_QUICKFIND_H

typedef char Element;

typedef struct
{
    Element * data;         // 实际的数据
    int * group;            // 对应的老大
    int n;                  // 初始化的元素个数
    int capacity;           // 申请的总容量大小
}QuickFindSet;
QuickFindSet* createQuickFindSet(int n);
void releaseQuickFindSet(QuickFindSet* QFset);
void initQuickFindSet(QuickFindSet* QFset, const Element* data, int n);
// 合并
void unionQuickFindSet(QuickFindSet* QFset, Element a, Element b);
// 查找是否相同
int isSameQuickFindSet(QuickFindSet* QFset, Element a, Element b);
#endif //DS_QUICKFIND_H
