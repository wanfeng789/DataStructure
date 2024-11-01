
/*
 *      十字链表
 */
#ifndef DS_CROSSLINKER_H
#define DS_CROSSLINKER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 十字链表的边定义
typedef struct _arc_edge_
{
    int tailVertext;    // 尾节点
    struct _arc_edge_* tailNext;    // 下一个出度节点
    int headVertext;        // 头结点
    struct _arc_edge_* headNext;        // 下一个入度节点
    int weight;                 // 权重
}ArcEdge;
// 十字链表的每个节点
typedef struct
{
    char* show;     // 显示节点名字
    int no;         // 节点下标
    ArcEdge * firstOut;     // 出度
    ArcEdge * firstIn;      // 入度

}ArcNode;
// 十字链表头
typedef struct
{
    ArcNode * nodes;        // 节点数
    int node_num;       // 每个节点的数量
    int edge_num;       // 每个边的数量

}CrossGraph;

CrossGraph* createCrossGraph(int n);
void releaseCrossGraph(CrossGraph* crossGraph);
void initCrossGraph(CrossGraph* crossGraph, char* name[], int n);
// 添加边关系
void addCrossGraphEdge(CrossGraph* crossGraph, int tail, int head, int w);
// 计算节点的出度数量
int getOutDegreeCrossGraph(CrossGraph* crossGraph, int v);
// 计算节点的入度数量
int getInDegreeCrossGraph(CrossGraph* crossGraph, int v);

#endif //DS_CROSSLINKER_H
