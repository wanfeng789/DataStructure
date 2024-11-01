#include "adjacentList.h"

void initGraph(ArcGraph* arcGraph)
{
    char* name[] = {"A", "B", "C", "D", "E"};
    initArcGraph(arcGraph, name, sizeof(name) / sizeof(name[0]), 1);
    addArcGraphEdge(arcGraph, 0, 4, 1);
    addArcGraphEdge(arcGraph, 0, 3, 1);
    addArcGraphEdge(arcGraph, 0, 1, 1);
    addArcGraphEdge(arcGraph, 1, 4, 1);
    addArcGraphEdge(arcGraph, 1, 2, 1);
    addArcGraphEdge(arcGraph, 2, 0, 1);
    addArcGraphEdge(arcGraph, 3, 2, 1);

}
void test01()
{
    int n = 5;
    ArcGraph * arcGraph = createArcGraph(n);
    initGraph(arcGraph);
    printf("ArcGraph Edge num: %d\n", arcGraph->edgeNum);
    printf("DFS: ");
    DFSArcGraph(arcGraph, 0);
    printf("\n");

    releaseArcGraph(arcGraph);
}

int main()
{
    test01();

    return 0;
}
