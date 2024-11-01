
#include "Kruskal.h"
int initEdgeSet(MGraph *mGraph, EdgeSet *edgeSet)
{
    int cnt = 0;    // 统计边的个数
    for(int i = 0; i < mGraph->nodeNum; ++i)
    {
        // 只需要添加上三角节点的边关系即可
        for(int j = i + 1; j < mGraph->nodeNum; ++j)
        {
            // 说明边有关系
            if(mGraph->edges[i][j] > 0)
            {
                edgeSet[cnt].begin = i;
                edgeSet[cnt].end = j;
                edgeSet[cnt].w = mGraph->edges[i][j];
                ++cnt;
            }
        }
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    return (*(EdgeSet*)a).w - (*(EdgeSet*)b).w;
}
void sortEdgeSet(EdgeSet *edgeSet, int num)
{
   qsort(edgeSet, num, sizeof(EdgeSet), cmp);
}
static int getRoot(int* uSet, int a)
{
    if(uSet[a] == a)
    {
        return a;
    }
    return uSet[a] = getRoot(uSet, uSet[a]);
}
int kruskal(const EdgeSet *edgeSet, const MGraph *mGraph, int numEdge, EdgeSet *resEdges)
{
    // 1. 创立并查集并初始化
    int *uSet = (int*)malloc(sizeof(int) * mGraph->nodeNum);
    for(int i = 0; i < mGraph->nodeNum; ++i)
    {
        uSet[i] = i;
    }
    int sum = 0;        // 获得最小生成树的权值之和
    int cnt = 0;
    // 2.查找最小的且没有连接的两点的边关系
    int u, v, w;
    for(int i = 0; i < numEdge; ++i)
    {
         u = edgeSet[i].begin;
         v = edgeSet[i].end;
         w = edgeSet[i].w;
        int uf = getRoot(uSet, u);
        int vf = getRoot(uSet, v);
        if(uf != vf)
        {
            sum += w;
            uSet[vf] = uSet[uf];    // 更换老大
            // 得到最小生成树序列
            resEdges[cnt].begin = u;
            resEdges[cnt].end = v;
            resEdges[cnt].w = w;
            ++cnt;
        }
    }
    free(uSet);
    return sum;
}
