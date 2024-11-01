

#ifndef DS_KRUSKAL_H
#define DS_KRUSKAL_H
#include "adjacentMatrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 定义边集数组
typedef struct
{
    int begin;      // 开始节点
    int end;        // 结束节点
    int w;          // 权重
}EdgeSet;

// 初始化边集数组
int initEdgeSet(MGraph* mGraph, EdgeSet* edgeSet);
// 排序边集数组的边
void sortEdgeSet(EdgeSet* edgeSet, int num);

// 开始计算
int kruskal(const EdgeSet* edgeSet, const MGraph* mGraph, int numEdge, EdgeSet* resEdges);

#endif //DS_KRUSKAL_H
