#include "adjacentMatrix.h"

void initMatrixGraph(MGraph* graph)
{
    char* name[] = {"V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8"};
    // 构造顶点集
    initMGraph(graph, name, sizeof(name)/ sizeof(name[0]), 0, INF);
    // 构造边逻辑
    addMGraphEdge(graph, 0, 1, 1);
    addMGraphEdge(graph, 0, 2, 1);
    addMGraphEdge(graph, 1, 3, 1);
    addMGraphEdge(graph, 1, 4, 1);
    addMGraphEdge(graph, 2, 5, 1);
    addMGraphEdge(graph, 2, 6, 1);
    addMGraphEdge(graph, 3, 7, 1);
    addMGraphEdge(graph, 4, 7, 1);
    addMGraphEdge(graph, 5, 6, 1);
}
void test01()
{
    MGraph graph;
    initMatrixGraph(&graph);
    printf("Matrix Edge num: %d\n", graph.edgeNum);
    printf("DFS: ");
    DFSMGraph(&graph, 0);
    printf("\n");
    memsetFlag();
    printf("BFS: ");
    BFSMGraph(&graph, 0);
    printf("\n");
}

int main()
{
    test01();
    return 0;
}
