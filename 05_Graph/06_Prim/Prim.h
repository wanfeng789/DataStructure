#ifndef PRIM_H
#define PRIM_H
#include "adjacentMatrix.h"
/* graph 邻接矩阵存储的图
 * result 边集数组，最小生成树的边结果
 * startV 随机选择的第一个激活顶点编号
 * return 最小生成树的权值
 * */
// 定义边集数组
typedef struct
{
    int begin;      // 开始节点
    int end;        // 结束节点
    int w;          // 权重
}EdgeSet;
int PrimMGraph(MGraph *graph, int startV, EdgeSet *result);
#endif
