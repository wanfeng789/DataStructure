#include <stdlib.h>
#include "Prim.h"

int PrimMGraph(MGraph *graph, int startV, EdgeSet *result) {
	int *cost;				// 图中各顶点的权值
	int *mark;				// 标记激活状态
	int *visit;				// 定义从哪个顶点访问到这个顶点
	int sum = 0;			// 权值之和
	int min, k;

	cost = (int *) malloc(sizeof(int ) * graph->nodeNum);
	mark = (int *) malloc(sizeof(int ) * graph->nodeNum);
	visit = (int *) malloc(sizeof(int ) * graph->nodeNum);
	if (cost == NULL || mark == NULL || visit == NULL) {
		return 0;
	}
	// 1. 更新第一个节点
	for (int i = 0; i < graph->nodeNum; ++i) {
		cost[i] = graph->edges[startV][i];
		if (cost[i] < INF) {
			visit[i] = startV;
		} else {
			visit[i] = -1;
		}
		mark[i] = 0;
	}
	mark[startV] = 1;			// 激活开始触发循环
	// 2. 循环激活节点，查找cost里最小的值，添加到result，更新mark visit cost
	for (int i = 0; i < graph->nodeNum - 1; ++i) {		// 找剩下的n-1个节点，激活边
		// 从cost数组里找到未激活节点的最小值
		min = INF;
		for (int j = 0; j < graph->nodeNum; ++j) {
			if (mark[j] == 0 && cost[j] < min) {
				min = cost[j];
				k = j;
			}
		}
		mark[k] = 1;
		result[i].begin = visit[k];
		result[i].w = min;
		result[i].end = k;
		sum += min;
		// 3. 每激活一个顶点后，更新cost和访问记录，k索引的节点对应的边来跟cost里的值比较
		for (int j = 0; j < graph->nodeNum; ++j) {
			if (mark[j] == 0 && graph->edges[k][j] < cost[j]) {
				cost[j] = graph->edges[k][j];
				visit[j] = k;
			}
		}
	}
	free(cost);
	free(mark);
	free(visit);
	return sum;
}
