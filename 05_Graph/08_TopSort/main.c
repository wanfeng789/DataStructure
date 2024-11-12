#include <stdio.h>
#include <stdlib.h>
#include "topologicalSort.h"

ArcGraph *setupAGraph() {
	char *names[] = {"0", "1", "2", "3",
					 "4", "5", "6"};
	int n = sizeof(names) / sizeof(names[0]);
    ArcGraph *graph = createArcGraph(n);
	if (graph == NULL) {
		return NULL;
	}
	initArcGraph(graph, names, n, 1);
	addArcGraphEdge(graph, 0, 1, 1);
	addArcGraphEdge(graph, 0, 2, 1);
	addArcGraphEdge(graph, 0, 3, 1);
	addArcGraphEdge(graph, 1, 2, 1);
	addArcGraphEdge(graph, 1, 4, 1);
	addArcGraphEdge(graph, 2, 4, 1);
	addArcGraphEdge(graph, 2, 5, 1);
	addArcGraphEdge(graph, 3, 5, 1);
	addArcGraphEdge(graph, 4, 6, 1);
	addArcGraphEdge(graph, 5, 4, 1);
	addArcGraphEdge(graph, 5, 6, 1);
	return graph;
}

int main() {
    ArcGraph *graph  = setupAGraph();
	int *result;
	int res_len;
	if (graph == NULL) {
		return -1;
	}
	int res = TopologicalSortAGraph(graph, &result, &res_len);
	for (int i = 0; i < res_len; ++i) {
		printArcGraph(&graph->nodes[result[i]]);
	}
	printf("\nresult = %d\n", res);
	free(result);
	return 0;
}
