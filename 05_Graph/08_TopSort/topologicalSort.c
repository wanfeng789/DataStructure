#include <stdlib.h>
#include <string.h>
#include "topologicalSort.h"
/* 拓扑排序的算法过程：
 * 1. 从有向图中选择一个没有前驱（入度为0）的顶点，输出
 * 2. 删除上一步输出的顶点，从这个顶点出发，遍历他的出度边，每发现一个边，就把inDegree数组对应下标进行减1
 * 3. 重复上面2步
 * 拓扑排序的算法，需要引入一个入度数组
 * */
int TopologicalSortAGraph(ArcGraph *graph, int **res, int *res_len) {
	int *inDegree;
	int count = 0;
	int *result;

	result = (int *) malloc(sizeof(int ) * graph->nodeNum);
	inDegree = (int *) malloc(sizeof(int ) * graph->nodeNum);
	if (inDegree == NULL) {
		return -1;
	}
	memset(inDegree, 0, sizeof(int ) * graph->nodeNum);
	// 1. 更新入度表
	for (int i = 0; i < graph->nodeNum; ++i) {
		if (graph->nodes[i].firstEdge) {
			// 引入辅助节点指针
			ArcEdge *edge = graph->nodes[i].firstEdge;
			while (edge) {
				++inDegree[edge->no];
				edge = edge->next;
			}
		}
	}
	// 查找入度表里度为0的顶点，只要入度为0，就入栈（入队），初始化栈
	int *stack;
	int top = -1;
	stack = (int *) malloc(sizeof(int ) * graph->nodeNum);
	if (stack == NULL) {
		free(inDegree);
		return -1;
	}
	for (int i = 0; i < graph->nodeNum; ++i) {
		if (inDegree[i] == 0) {
			stack[++top] = i;
		}
	}
	// 根据栈的数据，一个个弹出节点，每弹出一个节点，删除（查找）对应的边，更新inDegree
	// 直到栈为空
	int index;
	while (top != -1) {
		index = stack[top--];
		result[count] = index;
		++count;
		// visitAGraphNode(&graph->nodes[index]);
		// 更新入度
		ArcEdge *edge = graph->nodes[index].firstEdge;
		while (edge) {
			--inDegree[edge->no];
			if (inDegree[edge->no] == 0) {	// 如果更新inDegree之后，已经为0，入栈
				stack[++top] = edge->no;
			}
			edge = edge->next;
		}
	}
	free(stack);
	free(inDegree);
	*res = result;
	*res_len = count;
	// 栈是空，统计已经出了多少次和顶点的个数来比较
	if (count == graph->nodeNum) {
		return 0;
	} else {
		return 1;
	}
}
