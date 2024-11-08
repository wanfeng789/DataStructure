#ifndef DIJKSTRA_SHORT_PATH_H
#define DIJKSTRA_SHORT_PATH_H

#include "adjacentMatrix.h"
#define INF 1E4
/* 单源点最短路径算法Dijkstra算法
 * 某一个点找其余顶点的最短路径
 * dist : 记录图中每个顶点到源点的最短路径值，便于后期的查询
 * path : 记录每个节点从哪个节点来访问到，相当于就是这个顶点的父节点
 * */
void DijkstraMGraph(const MGraph *graph, int start, int dist[], int path[]);
/* 通过path打印出源点到pos点的最短路径 */
void showShortPath(const int path[], int num, int pos);
#endif
