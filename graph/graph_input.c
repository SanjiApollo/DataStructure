#include"graph_input.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void GetTheEdgesWeight(char *edges, int *elength, int *weight, int *wlength);

_G_Input_Stack _G_Input_InitStack() {
    _G_Input_Stack stack = (_G_Input_Stack) malloc (sizeof(struct _G_Input_Stack));
    if(stack == NULL) {
        printf("failed to create _G_Input_Stack!\n");
        exit(1);
    }
    stack->top = -1;
}

bool _G_Input_IsEmptyStack(_G_Input_Stack s) {
    return s->top == -1;
}

bool _G_Input_IsFullStack(_G_Input_Stack s) {
    return s->top == _G_INPUT_MAX_STACK_SIZE -1;
}

void _G_Input_Push(_G_Input_Stack s, char ch) {
    if(_G_Input_IsFullStack(s)) {
        printf("_G_Input_Stack is full!\n");
        exit(1);
    }
    s->top ++;
    s->array[s->top] = ch;
}

char _G_Input_Pop(_G_Input_Stack s) {
    if(_G_Input_IsEmptyStack(s)) {
        printf("_G_Input_Stack is empty!\n");
        exit(1);
    }
    return s->array[s->top --];
}

char _G_Input_GetTop(_G_Input_Stack s) {
    if(_G_Input_IsEmptyStack(s)) {
        printf("_G_Input_Stack is empty!\n");
        exit(1);
    }
    return s->array[s->top];
}

void _G_Input_MakeEmptyStack(_G_Input_Stack s) {
    s->top = -1;
}

void _G_Input_DestoryStack(_G_Input_Stack s) {
    free(s);
}

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
    int isEOF = 0;
    char edges[1024];
    int weight[512];
    int elength, wlength;
    if(gkind == 1 || gkind == 3) {
        printf("give all the arcs，the fromat is (v1, v2, weight)：\n");
            //GetTheArcs(&v1, &v2, &weight, &isEOF);
            // if(isEOF == 1) break;
        GetTheEdgesWeight(edges, &elength, weight, &wlength);
        for(int i = 0, j = 0; i < elength; i += 2, j ++) {
            v1 = edges[i];
            v2 = edges[i + 1];
            w = weight[j];
            G_InsertEdge(g, v1, v2, w);
        }
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

void GetTheEdgesWeight(char *edges, int *elength, int *weight, int *wlength) {
    char ch;
    char str[30];
    int position = 29;
    int eposition = 0, wposition = 0;
    _G_Input_Stack stack = _G_Input_InitStack();
    int length = 0;
    while(true) {
        while(isspace(ch = getchar()));
        if(ch == EOF) break;
        _G_Input_Push(stack, ch);
    }

    if(_G_Input_GetTop(stack) != ')') {
        printf("wrong edge format\n");
        exit(1);
    }
    while(!_G_Input_IsEmptyStack(stack)) {
        position = 29;
        while((ch = _G_Input_Pop(stack)) != '(') {
            str[position --] = ch;
        }
        
        edges[eposition ++] = str[position + 1];
        edges[eposition ++] = str[position + 3];
        int w = Str2Int(&str[position + 5], 24 - position);
        weight[wposition ++] = w;
    }
    *elength = eposition;
    *wlength = wposition;

    _G_Input_DestoryStack(stack);
}
        


















