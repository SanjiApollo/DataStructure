#include"graph_input.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void MakeTheGraph(Graph g) {
    // 输入得到图的类型
    int gkind;

    printf("please give all the vetexes(Ctrl+D to end input):\n");
    char vertex;
    while(1) {
        while(isspace(vertex = getchar()));
        if(vertex == EOF) break;
        G_InsertVertex(g, vertex);
    }

    // 得到图的类型
    printf("what's the kind of the graph?");
    printf("  0.DG  1.DN  2.UDG  3.UDN\n the kind is: ");

    while(1) {
        scanf("%d", &gkind);
        if(gkind != 0 && gkind != 1 && gkind != 2 && gkind != 3) {
            printf("wrong number for graph kind, try again\n");
        } else {
            break;
        }
    }

    switch (gkind) {
        case 0: g->gkind = _GK_DG; break;
        case 1: g->gkind = _GK_DN; break;
        case 2: g->gkind = _GK_UDG; break;
        case 3: g->gkind = _GK_UDN; break;
    }

    char v1, v2;
    int w;
    int edgenums;

    if(gkind == 1 || gkind == 3) {
        char *edges = (char*) malloc (sizeof(char) * MAX_EDGE_NUMS * 2);
        int *weights = (int*) malloc (sizeof(int) * MAX_EDGE_NUMS);
        if(edges == NULL || weights == NULL) {
            printf("can't create edges and weights!\n");
            exit(1);
        }
        printf("give all the arcs，the fromat is (v1, v2, weight)：\n");
        GetEdgesWithWeight(edges, weights, &edgenums);
/*
 *what's wrong with the input?
        for(int i = 0; i < 2 * edgenums; ++i) {
            printf("%c ", edges[i]);
        }
*/
        for(int i = 0; i < edgenums; ++ i) {
            G_InsertEdge(g, edges[2 * i], edges[2 * i + 1], weights[i]);
        }
        free(edges);
        free(weights);
    }
    if(gkind == 0 || gkind == 2) {
        printf("give all the edges，the format is (v1, v2)：\n");
            //GetTheEdges(&v1, &v2, &isEOF);
            // if(isEOF == 1) break;
            G_InsertEdge(g, v1, v2, 0);
    }
}

bool IsDigitalStr(char *digitStr, int length) {
    for(int i = 0; i != length; ++i) {
        if(!isdigit(digitStr[i]))
            return false;
    }
    return true;
}

int Str2Int(char *digtStr, int length) {
    // 默认十进制
    if(!IsDigitalStr(digtStr, length)) {
        printf("can't transfer str to integer!\n");
        exit(1);
    }
    int value = 0;
    int coeff = 1;
    for(int i = length - 1; i != -1; -- i, coeff *= 10) {
        value += digtStr[i] * coeff;
    }
    return value;
}

void GetEdgesWithWeight(char *edges, int *weights, int *edgenums) {
    char ch;
    int nums = 0;
    char str[50];
    int count = 0;
    int tmpw;
    while(true) {
        while(isspace(ch = getchar()));
        if(ch == EOF) break;
        if(ch != ')' && count < 50) {
            str[count ++] = ch;
        } else if(count == 50) {
            printf("the edges format is wrong!\n");
            exit(1);
        } else {
            if(str[0] != '(') {
                printf("edges format begin with a \'(\'\n");
                exit(1);
            }
            if(!isalpha(str[1]) || !isalpha(str[3])) {
                printf("the format (%c, %c) is wrong\n", str[1], str[3]);
                exit(1);
            }
            tmpw = Str2Int(str + 5, count - 5);
            weights[nums] = tmpw;
            edges[2 * nums] = str[1];
            edges[2 * nums + 1] = str[3];
            *edgenums = ++ nums;

            count = 0;
        }
    }
}

