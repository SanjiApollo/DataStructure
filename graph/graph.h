#ifndef DS_GRAPH_H
#define DS_GRAPH_H

/*
 *该头文件定义的图，用作学习图相关算法，结构从简
 *图的顶点信息接收一个大写字母，自动分配编号
 *图可以采用邻接矩阵或者邻接表存储
 *图的类型可以是无向图，有向图，网
 */

// 研究范围是20个顶点，380条以内的边
#define MAX_VERTEX_NUMS 20
#define MAX_EDGE_NUMS 380

typedef enum { _GK_DG, _GK_DN, _GK_UDG, _GK_UDN } GraphKind;

struct Graph;
typedef struct Graph *Graph;

struct VertexNode;
typedef struct VertexNode VertexNode;

struct EdgeNode;
typedef struct EdgeNode EdgeNode;

struct Graph {
    GraphKind gkind;
	VertexNode *varray[MAX_VERTEX_NUMS];
	int vnums;
    int enums;
};

struct VertexNode {
    char vname;     // 简化起见，顶点是一个字符
    EdgeNode *firstArc;
};

struct EdgeNode {
    int vnum;
    int weight;
    EdgeNode *nextArc;
};

// 初始化及建立图
Graph InitGraph();
void MakeGraph(Graph g);
void G_InsertVertex(Graph g, char vertex);
void G_InsertEdge(Graph g, char v1, char v2, int weight);

// 销毁图
void G_DestoryGraph(Graph g);

// 图的遍历
void G_BFS(Graph g, void (*Visit)(char vname));
void G_DFS(Graph g, void (*Visit)(char vname));

// 辅助工具
void VisitAllEdges(Graph g, void (*Visit)(char vname));
void VisitAllEdgesWithWeight(Graph g);

#endif
