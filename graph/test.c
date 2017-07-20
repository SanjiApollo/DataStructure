#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

void Visit(char vname);
void Seperator();

int main() {
	Graph g = InitGraph();
	MakeGraph(g);
    // VisitAllEdges(g, Visit);
    VisitAllEdgesWithWeight(g);
    Seperator();
    printf("DFS: ");
    G_DFS(g, Visit);
    Seperator();
    printf("BFS: ");
    G_BFS(g, Visit);
    Seperator();
}

void Visit(char vname) {
    printf("%c ", vname);
}

void Seperator() {
    printf("\n------------------------------------\n");
}
