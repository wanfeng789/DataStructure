
#include "Kruskal.h"

void setMGraph(MGraph* mGraph, int initValue)
{
    char* names[] = {"A", "B", "C", "D", "E", "F", "G"};

    initMGraph(mGraph, names, sizeof(names) / sizeof(names[0]), 0, initValue);

    addMGraphEdge(mGraph, 0, 1, 12);
    addMGraphEdge(mGraph, 0, 5, 16);
    addMGraphEdge(mGraph, 0, 6, 14);
    addMGraphEdge(mGraph, 1, 2, 10);
    addMGraphEdge(mGraph, 1, 5, 7);
    addMGraphEdge(mGraph, 2, 3, 3);
    addMGraphEdge(mGraph, 2, 4, 5);
    addMGraphEdge(mGraph, 2, 5, 6);
    addMGraphEdge(mGraph, 3, 4, 4);
    addMGraphEdge(mGraph, 4, 5, 2);
    addMGraphEdge(mGraph, 4, 6, 8);
    addMGraphEdge(mGraph, 5, 6, 9);

}
void test01()
{
    MGraph mGraph;
    EdgeSet * edgeSet;  // 开始的边集数组
    EdgeSet * resSet;   // 得到的最小生成树的边集数组
    int k = 0;          // 得到的最小生成树的边数
    setMGraph(&mGraph, 0);
    edgeSet = (EdgeSet*)malloc(sizeof(EdgeSet) * mGraph.edgeNum);
    k = initEdgeSet(&mGraph, edgeSet);
    printf("edge num: %d\n", k);
    sortEdgeSet(edgeSet, k);
    resSet = (EdgeSet*) malloc(sizeof(EdgeSet) * (mGraph.nodeNum - 1));
    int sum = kruskal(edgeSet, &mGraph, k, resSet);
    printf("sum = %d\n", sum);
    for(int i = 0; i < mGraph.nodeNum - 1; ++i)
    {
        printf("NO:%d, [%s]---%d---[%s]\n", i + 1, mGraph.vertex[resSet[i].begin].show, resSet[i].w,
               mGraph.vertex[resSet[i].end].show);
    }
    free(edgeSet);
    free(resSet);
}
int main()
{
    test01();
    return 0;
}