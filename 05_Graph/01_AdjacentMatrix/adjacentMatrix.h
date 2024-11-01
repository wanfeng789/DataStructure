

#ifndef DS_ADJACENTMATRIX_H
#define DS_ADJACENTMATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 邻接矩阵

#define MaxNodeNum 20         // 最大的节点数
#define INF 1e3                 // 自定义最大值
// 邻接矩阵的节点
typedef struct
{
    int no;             // 节点的下标
    char* show;         // 展示节点的信息
}MatrixVertex;

// 邻接矩阵的边
typedef int MatrixEdge;

// 封装成结构体

typedef struct
{
    MatrixVertex vertex[MaxNodeNum];            // 节点
    int nodeNum;                                // 存储的节点的数量
    MatrixEdge edges[MaxNodeNum][MaxNodeNum];   // 边的关系
    int edgeNum;                                // 边的数量
    int directed;                               // 表示是否有向还是无向
}MGraph;


// 初始化 names数组存节点的名字
void initMGraph(MGraph* graph, char* names[], int num, int direct, int initEdgevalue);

// 增加边的关系
void addMGraphEdge(MGraph *graph, int x, int y, int w);

//深度遍历
void DFSMGraph(MGraph* graph, int v);
// 广度遍历
void BFSMGraph(MGraph* graph, int v);
// 打印信息
void printMGraph(MatrixVertex *v);
// 清空标记位数组
void memsetFlag();
#endif //DS_ADJACENTMATRIX_H
