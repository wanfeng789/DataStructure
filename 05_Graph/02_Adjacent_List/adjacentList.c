
#include "adjacentList.h"

ArcGraph *createArcGraph(int n)
{
    ArcGraph * arcGraph = (ArcGraph*)malloc(sizeof(ArcGraph));
    arcGraph->nodeNum = 0;
    arcGraph->edgeNum = 0;
    arcGraph->visit = (int*)malloc(sizeof(int) * n);
    arcGraph->nodes = (ArcNode*)malloc(sizeof(ArcNode) * n);
    memset(arcGraph->visit, 0, sizeof(int) * n);
    memset(arcGraph->nodes, 0, sizeof(ArcNode) * n);
    return arcGraph;
}

void releaseArcGraph(ArcGraph *arcGraph)
{
    for(int i = 0; i < arcGraph->nodeNum; ++i)
    {
        ArcEdge * p = arcGraph->nodes[i].firstEdge;
        while(p)
        {
            p = p->next;
            free(arcGraph->nodes[i].firstEdge);
            arcGraph->nodes[i].firstEdge = p;
            --arcGraph->edgeNum;
        }
    }
    free(arcGraph->nodes);
    free(arcGraph->visit);
    printf("\nArcEdgeNum: %d\n", arcGraph->edgeNum);
    free(arcGraph);
}

void initArcGraph(ArcGraph *arcGraph, char **name, int num, int direct)
{
    arcGraph->nodeNum = num;
    arcGraph->directed = direct;
    for(int i = 0; i < num; ++i)
    {
        arcGraph->nodes[i].no = i;
        arcGraph->nodes[i].show = name[i];
        arcGraph->nodes[i].firstEdge = NULL;
    }
}
static ArcEdge* createArcEdge(int v, int w)
{
    ArcEdge * arcEdge = (ArcEdge*)malloc(sizeof(ArcEdge));
    arcEdge->no = v;
    arcEdge->w = w;
    arcEdge->next = NULL;
    return arcEdge;
}
void addArcGraphEdge(ArcGraph *arcGraph, int x, int y, int w)
{
    if(x < 0 || x >= arcGraph->nodeNum || y < 0 || y > arcGraph->nodeNum)
    {
        return;
    }
    // 采用头插法增加边关系
    ArcEdge * arcEdge = createArcEdge(y, w);
    arcEdge->next = arcGraph->nodes[x].firstEdge;
    arcGraph->nodes[x].firstEdge = arcEdge;
    ++arcGraph->edgeNum;
    if(arcGraph->directed == 0)
    {
        arcEdge = createArcEdge(x, w);
        arcEdge->next = arcGraph->nodes[y].firstEdge;
        arcGraph->nodes[y].firstEdge = arcEdge;
        ++arcGraph->edgeNum;
    }
}

void printArcGraph(ArcNode *v) {
    printf("\t%s", v->show);
}

void DFSArcGraph(ArcGraph *arcGraph, int v)
{
    printArcGraph(&arcGraph->nodes[v]);
    arcGraph->visit[v] = 1;
    ArcEdge * p = arcGraph->nodes[v].firstEdge;
    while(p)
    {
        if(arcGraph->visit[p->no] == 0)
        {
            DFSArcGraph(arcGraph, p->no);
        }
        p = p->next;
    }
}
