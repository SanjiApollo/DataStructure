#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"graph.h"
#include"graph_input.h"

void MakeGraph(Graph g) {
    if(g == NULL) {
        printf("graph doesn't exist! init one first!\n");
        exit(1);
    }
    MakeTheGraph(g);
}

VertexNode* MakeVertexNode();
Graph InitGraph() {
	Graph graph = (Graph) malloc (sizeof(struct Graph));
	if(graph == NULL) {
		printf("memory is full, failed to create a graph!\n");
		exit(1);
	}
    // 初始化图
	graph->vnums = 0;
	graph->enums = 0;
    for(int i = 0; i < MAX_VERTEX_NUMS; ++i) {
        graph->varray[i] = MakeVertexNode();
    }
	return graph;
}
VertexNode* MakeVertexNode() {
    VertexNode *node = (VertexNode*) malloc (sizeof(VertexNode));
    if(node == NULL) {
        printf("failed to create a vertex node!\n");
        exit(1);
    }
    node->firstArc = NULL;
    return node;
}


void G_InsertVertex(Graph g, char vertex) {
    if(g->vnums == MAX_VERTEX_NUMS) {
        printf("vertex array is full!\n");
        exit(1);
    }
    // 保持插入顶点的互异性
    for(int i = 0; i < g->vnums; ++ i) {
        if(vertex == g->varray[i]->vname) {
            printf("vertex %c already exists!\n", vertex);
            return ;
        }
    }
    g->varray[g->vnums]->vname = vertex;
    g->vnums ++;
}

int GetVertexNumByName(Graph g, char vname);
void _G_InsertEdge(Graph g, char v1, char v2, int weight, bool isUG);
bool HasTheEdge(Graph g, int v1num, int v2num);
void G_InsertEdge(Graph g, char v1, char v2, int weight) {
    switch(g->gkind) {
        case _GK_UDN:
        case _GK_UDG: _G_InsertEdge(g, v1, v2, weight, true);
                      break;
        case _GK_DG: 
        case _GK_DN: _G_InsertEdge(g, v1, v2, weight, false);
                      break;
    }
}
int GetVertexNumByName(Graph g, char vname) {
    for(int i = 0; i < g->vnums; ++ i) {
        if(vname == g->varray[i]->vname) {
            return i;
        }
    }
    return -1;
}
void _G_InsertEdge(Graph g, char v1, char v2, int weight, bool isUG) {
    int v1num = GetVertexNumByName(g, v1);
    int v2num = GetVertexNumByName(g, v2);
    if(v1num == -1 || v2num == -1) {
        printf("the vertex doesn't exist! (%c, %c)\n", v1, v2);
        exit(1);
    }
    if(HasTheEdge(g, v1num, v2num)) {
        printf("the edge already exists!\n");
        return ;
    }
    EdgeNode *enode = NULL;
    enode = (EdgeNode*) malloc (sizeof(EdgeNode));
    if(enode == NULL) {
        printf("failed to create EdgeNode!\n");
        exit(1);
    }
    enode->vnum = v2num;
    enode->weight = weight;
    enode->nextArc = g->varray[v1num]->firstArc;
    g->varray[v1num]->firstArc = enode;

    if(isUG) {
        enode = (EdgeNode*) malloc (sizeof(EdgeNode));
        if(enode == NULL) {
            printf("failed to create EdgeNode!\n");
            exit(1);
        }
        enode->vnum = v1num;
        enode->weight = weight;
        enode->nextArc = g->varray[v2num]->firstArc;
        g->varray[v2num]->firstArc = enode;
    }
}
bool HasTheEdge(Graph g, int v1num, int v2num) {
    EdgeNode *p = g->varray[v1num]->firstArc;
    for(; p != NULL && p->vnum != v2num; p = p->nextArc);
    return p != NULL;
}
// void G_BFS(Graph g);

void _G_DFS(Graph g, _Bool *visited, int vnum, void (*Visit)(char vname));
void G_DFS(Graph g, void (*Visit)(char data)) {
    _Bool *visited = (_Bool*) malloc (sizeof(_Bool) * g->vnums);
    for(int i = 0; i < g->vnums; ++i) visited[i] = 0;
    for(int i = 0; i < g->vnums; ++i) {
        if(!visited[i])
            _G_DFS(g, visited, i, Visit);
    }
}

void _G_DFS(Graph g, _Bool *visited, int vnum, void (*Visit)(char vname)) {
    visited[vnum] = 1;
    Visit(g->varray[vnum]->vname);
    for(EdgeNode *p = g->varray[vnum]->firstArc; p != NULL; p = p->nextArc) {
        if(!visited[p->vnum]) {
            _G_DFS(g, visited, p->vnum, Visit);
        }
    }
}

void G_DestoryGraph(Graph g) {
}

// 以下是辅助函数
void VisitAllEdges(Graph g, void (*Visit)(char vname)) {
    EdgeNode *p = NULL;     // 小心p的作用域范围
    for(int i = 0; i < g->vnums; ++ i) {
        p = g->varray[i]->firstArc;
        Visit(g->varray[i]->vname);
        while(p != NULL) {
            Visit(g->varray[p->vnum]->vname);
            p = p->nextArc;
        }
        printf("\n");
    }
}
