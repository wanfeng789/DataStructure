#include "crossLinker.h"

void init(CrossGraph *crossGraph)
{
    char* name[] = {"V0", "V1", "V2", "V3"};
    initCrossGraph(crossGraph,name, 4);
    addCrossGraphEdge(crossGraph, 0, 3,1);
    addCrossGraphEdge(crossGraph, 1, 0,1);
    addCrossGraphEdge(crossGraph, 1, 2,1);
    addCrossGraphEdge(crossGraph, 2, 1,1);
    addCrossGraphEdge(crossGraph, 2, 0,1);

}
void test01()
{
    CrossGraph* crossGraph = createCrossGraph(4);
    init(crossGraph);
    int InDegree =  getInDegreeCrossGraph(crossGraph,0);
    int OutDegree =  getOutDegreeCrossGraph(crossGraph,0);
    printf("V0 OutDegree: %d\t, InDegree %d\n", OutDegree, InDegree);

    releaseCrossGraph(crossGraph);
}
int main()
{
    test01();


    return 0;
}


