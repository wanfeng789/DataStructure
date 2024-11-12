#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H
#include "adjacentList.h"

// 实现拓扑排序，通过返回值来判断有向图是否有环 0表示无环，1表示有环，-1表示错误
int TopologicalSortAGraph(ArcGraph *graph, int **res, int *res_len);
#endif
