#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

void Visit(char vname);

int main() {
	Graph g = InitGraph();
	MakeGraph(g);
    VisitAllEdges(g, Visit);
    printf("\n DFS: ");
    G_DFS(g, Visit);
    printf("\n");
}

void Visit(char vname) {
    printf("%c ", vname);
}
