

#include "adjacentMatrix.h"

// 判断是否有重复边或者有无边
int isEdge(int weight)
{
    if(weight > 0 && weight < INF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void initMGraph(MGraph *graph, char **names, int num, int direct, int initEdgevalue)
{
    graph->directed = direct;
    graph->nodeNum = num;
    graph->edgeNum = 0;
    for(int i = 0; i < num; ++i)
    {
        graph->vertex[i].show = names[i];
        graph->vertex[i].no = i;
        for(int j = 0; j < num; ++j)
        {
            graph->edges[i][j] = initEdgevalue;
        }
    }
}

void addMGraphEdge(MGraph *graph, int x, int y, int w)
{
    if(x < 0 || x >= graph->nodeNum || y < 0 || y >= graph->nodeNum)
    {
        return;
    }
    // 判断 x y 是否已经有了边
    if(!isEdge(graph->edges[x][y]))
    {
        graph->edges[x][y] = w;
        // 如果为无向图
        if(!graph->directed)
        {
            graph->edges[y][x] = w;
        }
        ++graph->edgeNum;
    }
}
/*
 * 深度遍历 当前节点往深处走
 */
static int flagDFSV[MaxNodeNum] = {0};
void DFSMGraph(MGraph *graph, int v)
{
    printMGraph(&graph->vertex[v]);
    flagDFSV[v] = 1;
    for(int i = 0; i < graph->nodeNum; ++i)
    {
        // 是否有变关系 是否被访问过
        if(isEdge(graph->edges[v][i]) && flagDFSV[i] == 0)
        {
            DFSMGraph(graph, i);
        }
    }
}

void printMGraph(MatrixVertex* v)
{
    printf("\t%s", v->show);
}

void BFSMGraph(MGraph *graph, int v)
{
    int queue[MaxNodeNum];
    int front = 0, rear = 0;
    queue[rear++] = v;
    flagDFSV[v] = 1;
    int cur = 0;
    while(front != rear)
    {
        cur = queue[front];
        ++front;
        printMGraph(&graph->vertex[cur]);
        for(int i = 0; i < graph->nodeNum; ++i)
        {
            if(isEdge(graph->edges[cur][i]) && flagDFSV[i] == 0)
            {
                queue[rear++] = i;
                flagDFSV[i] = 1;
            }
        }
    }
}

void memsetFlag()
{
    memset(flagDFSV, 0, sizeof(flagDFSV));
}
