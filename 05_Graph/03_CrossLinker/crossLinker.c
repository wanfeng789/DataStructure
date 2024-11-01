
#include "crossLinker.h"

CrossGraph *createCrossGraph(int n)
{
    CrossGraph * crossGraph = (CrossGraph*)malloc(sizeof(CrossGraph));
    crossGraph->nodes = (ArcNode*)malloc(sizeof(ArcNode) * n);
    crossGraph->edge_num = 0;
    crossGraph->node_num = 0;
    return crossGraph;
}

void releaseCrossGraph(CrossGraph* crossGraph)
{
    if(crossGraph)
    {
        if(crossGraph->nodes)
        {
            ArcEdge * p = NULL;
            ArcEdge * tmp = NULL;
            for(int i = 0; i < crossGraph->node_num; ++i)
            {
                p = crossGraph->nodes[i].firstOut;
                while(p)
                {
                    tmp = p;
                    p = p->tailNext;
                    free(tmp);
                }
            }
            free(crossGraph->nodes);
        }
        free(crossGraph);
    }
}

void initCrossGraph(CrossGraph *crossGraph, char **name, int n)
{
    crossGraph->node_num = n;
    for(int i = 0; i < n; ++i)
    {
        crossGraph->nodes[i].no = i;
        crossGraph->nodes[i].show = name[i];
        crossGraph->nodes[i].firstIn = crossGraph->nodes[i].firstOut = NULL;
    }

}

void addCrossGraphEdge(CrossGraph *crossGraph, int tail, int head, int w)
{
    ArcEdge * edge = (ArcEdge*)malloc(sizeof(ArcEdge));
    edge->weight = w;
    // 头插法处理出度问题
    edge->tailVertext = tail;
    edge->tailNext = crossGraph->nodes[tail].firstOut;
    crossGraph->nodes[tail].firstOut = edge;
    // 头插法处理入度问题
    edge->headVertext = head;
    edge->headNext = crossGraph->nodes[head].firstIn;
    crossGraph->nodes[head].firstIn = edge;

    // 边的数量+1
    ++crossGraph->edge_num;
}

int getOutDegreeCrossGraph(CrossGraph *crossGraph, int v)
{
    int cnt = 0;
    ArcEdge *pOut = crossGraph->nodes[v].firstOut;
    while(pOut)
    {
        ++cnt;
        pOut = pOut->tailNext;
    }
    return cnt;
}

int getInDegreeCrossGraph(CrossGraph *crossGraph, int v)
{
    int cnt = 0;
    ArcEdge *pIn = crossGraph->nodes[v].firstIn;
    while(pIn)
    {
        ++cnt;
        pIn = pIn->headNext;
    }
    return cnt;
}
