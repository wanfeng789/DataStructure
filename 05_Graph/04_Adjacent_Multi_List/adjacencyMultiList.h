#ifndef ADJACENCY_MULTI_LIST_H
#define ADJACENCY_MULTI_LIST_H
// 邻接多重表，适用于无向图
// 边的节点
typedef struct amlEdge {
	int iVex;
	struct amlEdge *iNext;
	int jVex;
	struct amlEdge *jNext;
	int weight;
}MultiListEdge;
// 顶点结构
typedef struct {
	int no;
	char *show;
	MultiListEdge *firstEdge;
}MultiListVertex;
// 邻接多重表的图头
typedef struct {
	MultiListVertex *nodes;
	int vertexNum;
	int edgeNum;
}AdjacencyMultiList;

AdjacencyMultiList *createMultiList(int n);
void releaseMultiList(AdjacencyMultiList *graph);
void initMultiList(AdjacencyMultiList *graph, char *names[], int n);

// 插入边
int insertMultiList(AdjacencyMultiList *graph, int a, int b, int w);
// 删除边
int deleteMultiList(AdjacencyMultiList *graph, int a, int b);
#endif
