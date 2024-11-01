
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef DS_ADJACENTLIST_H
#define DS_ADJACENTLIST_H

// 邻接表

// 定义边关系
typedef struct _arcedge
{
    int no;         // 指向的节点
    int w;          // 权重
    struct _arcedge* next;      // 指向的下一个节点
}ArcEdge;

// 定义节点的关系
typedef struct
{
    int no;         // 定义节点
    char* show;     // 显示节点的信息
    ArcEdge * firstEdge;        // 节点指向的第一个边
}ArcNode;

// 封装成结构体
typedef struct
{
    ArcNode * nodes;        // 每个节点
    int nodeNum;            // 节点的个数
    int edgeNum;            // 边的个数
    int* visit;             // 是否被访问过
    int directed;          // 表示是否为有向图
}ArcGraph;

ArcGraph *createArcGraph(int n);
void releaseArcGraph(ArcGraph* arcGraph);
// 初始化节点
void initArcGraph(ArcGraph* arcGraph, char* name[], int num, int direct);
// 建立边的关系
void addArcGraphEdge(ArcGraph* arcGraph, int x, int y, int w);
// 深度遍历
void DFSArcGraph(ArcGraph* arcGraph, int v);
void printArcGraph(ArcNode * v);
#endif //DS_ADJACENTLIST_H
