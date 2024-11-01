#include <stdio.h>
#include <stdlib.h>
#include "adjacencyMultiList.h"

AdjacencyMultiList *createMultiList(int n) {
	AdjacencyMultiList *multiList = (AdjacencyMultiList *) malloc(sizeof(AdjacencyMultiList));
	multiList->nodes = (MultiListVertex *) malloc(sizeof(MultiListVertex) * n);
	multiList->vertexNum = n;
	multiList->edgeNum = 0;
	return multiList;
}

void initMultiList(AdjacencyMultiList *graph, char **names, int n) {
	for (int i = 0; i < n; ++i) {
		graph->nodes[i].no = i;
		graph->nodes[i].show = names[i];
		graph->nodes[i].firstEdge = NULL;
	}
}

int insertMultiList(AdjacencyMultiList *graph, int a, int b, int w) {
	// 1. 产生边
	MultiListEdge  *edge = (MultiListEdge  *) malloc(sizeof(MultiListEdge));
	edge->weight = w;
	// 2. 处理a的关系
	edge->iVex = a;
	edge->iNext = graph->nodes[a].firstEdge;
	graph->nodes[a].firstEdge = edge;
	// 3. 处理b的关系
	edge->jVex = b;
	edge->jNext = graph->nodes[b].firstEdge;
	graph->nodes[b].firstEdge = edge;
	++graph->edgeNum;
	return 0;
}

// 删除一个边，其实要有2个辅助指针，一个指向a节点的前置节点，一个是指向b节点前置节点
int deleteMultiList(AdjacencyMultiList *graph, int a, int b) {
	// 找到a编号的前一个节点
	MultiListEdge *aPreEdge = NULL;
	MultiListEdge *aCurEdge = graph->nodes[a].firstEdge;
	while (aCurEdge &&
		!((aCurEdge->iVex == a && aCurEdge->jVex == b) || (aCurEdge->jVex == a && aCurEdge->iVex == b))) {
		aPreEdge = aCurEdge;
		if (aCurEdge->iVex == a) {
			aCurEdge = aCurEdge->iNext;
		} else {
			aCurEdge = aCurEdge->jNext;
		}
	}
	if (aCurEdge == NULL)
		return -1;
	// 找到b编号的前置节点
	MultiListEdge *bPreEdge = NULL;
	MultiListEdge *bCurEdge = graph->nodes[b].firstEdge;
	while (bCurEdge &&
		!((bCurEdge->iVex == a && bCurEdge->jVex == b) || (bCurEdge->iVex == b && bCurEdge->jVex == a))) {
		bPreEdge = bCurEdge;
		if (bCurEdge->iVex == b) {
			bCurEdge = bCurEdge->iNext;
		} else {
			bCurEdge = bCurEdge->jNext;
		}
	}
	if (bCurEdge == NULL)
		return -1;
	if (aPreEdge == NULL) {
		if (aCurEdge->iVex == a) {
			graph->nodes[a].firstEdge = aCurEdge->iNext;
		} else {
			graph->nodes[a].firstEdge = aCurEdge->jNext;
		}
	} else {
		if (aPreEdge->iVex == a && aCurEdge->iVex == a) {
			aPreEdge->iNext = aCurEdge->iNext;
		} else if (aPreEdge->iVex == a && aCurEdge->jVex == a) {
			aPreEdge->iNext = aCurEdge->jNext;
		} else if (aPreEdge->jVex == a && aCurEdge->iVex == a) {
			aPreEdge->jNext = aCurEdge->iNext;
		} else {
			aPreEdge->jNext = aCurEdge->jNext;
		}
	}
	if (bPreEdge == NULL) {
		if (bCurEdge->iVex == b) {
			graph->nodes[b].firstEdge = bCurEdge->iNext;
		} else {
			graph->nodes[b].firstEdge = bCurEdge->jNext;
		}
	} else {
		if (bPreEdge->iVex == b && bCurEdge->iVex == b) {
			bPreEdge->iNext = bCurEdge->iNext;
		} else if (bPreEdge->iVex == b && bCurEdge->jVex == b) {
			bPreEdge->iNext = bCurEdge->jNext;
		} else if (bPreEdge->jVex == b && bCurEdge->iVex == b) {
			bPreEdge->jNext = bCurEdge->iNext;
		} else {
			bPreEdge->jNext = bCurEdge->jNext;
		}
	}
	free(aCurEdge);
	--graph->edgeNum;
	return 0;
}

