#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"binary_tree.h"

typedef char ElementType;

struct BiTreeNode {
	ElementType data;
	BiTree lchild;
	BiTree rchild;
};

void BiTreeAddRoot(BiTree * tree, ElementType data) {
	if(*tree == NULL) {
		BiTreeNode * node = (BiTreeNode*) malloc(sizeof(BiTreeNode));
		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		*tree = node;
	}
}

BiTreeNode* FindNodeX(BiTree tree, const char ch) {
	// 感觉有问题呀？
	if(!tree) {
		return NULL;
	}
	if(tree->data == ch) return tree;
	BiTreeNode *lp = FindNodeX(tree->lchild, ch);
	BiTreeNode *rp = FindNodeX(tree->rchild, ch);
	return lp?lp:rp;
}

BiTree MakeBiTreeByParent() {
	BiTree tree = NULL;
	char str[7];
	char ch;
	int count = 0;

	do {
		while(count < 7) {
			while(isspace(ch = getchar())) ;
			if(ch == EOF) break;
			str[count++] = ch;
		}

		if(str[0] != '(') {
			printf("first character must be a \'(\'\n");
			return NULL;
		}

		if(!isalpha(str[1]) || !(isalpha(str[3]) || str[3] == '#') ||
				!(str[5] == '#' || str[5] == 'r' || str[5] == 'l')) {
			printf("valid data must be a char or '#', position must be 'r' or 'l' or '#'\n");
			printf("%c %c %c\n", str[1], str[3], str[5]);
			return NULL;
		}

		if(str[2] != ',' || str[4] != ',') {
			printf("only comma can be a separator\n");
			return NULL;
		}

		if(str[6] != ')') {
			printf("bracket must be paired\n");
			return NULL;
		}
		count = 0;

		BiTreeNode *node = MakeBiTreeNode(str[1]);
		if(str[3] == '#') {
			tree = node;
		} else {
			BiTreeNode *p = FindNodeX(tree, str[3]);
			if(!p) {
				printf("there is no parent of %c yet\n", str[1]);
				return NULL;
			}
			if(str[5] == 'l') {
				p->lchild = node;
			} else if(str[5] == 'r') {
				p->rchild = node;
			}
		}
	} while(ch != EOF);
	return tree;
}

BiTree MakeEmpty(BiTree root) {
	if(root != NULL) {
		MakeEmpty(root->lchild);
		MakeEmpty(root->rchild);
		free(root);
	}
	return NULL;
}

void DestoryBiTree(BiTree root) {
}


void BiTreeInsertChild(BiTree root,
		BiTreeNode* parent, int LR, BiTreeNode* child) {
	if(LR == 0) {
		parent->lchild = child;
	} else if(LR == 1) {
		parent->rchild = child;
	}
}

BiTreeNode* MakeBiTreeNode(ElementType data) {
	BiTreeNode * node = (BiTreeNode*) malloc(sizeof(BiTreeNode));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void BiTreePreOrderTraverse(BiTree tree, void (*Visit)(ElementType data)) {
	if(tree != NULL) {
		Visit(tree->data);
		BiTreePreOrderTraverse(tree->lchild, Visit);
		BiTreePreOrderTraverse(tree->rchild, Visit);
	}
}
void BiTreeInOrderTraverse(BiTree tree, void (*Visit)(ElementType data)) {
	if(tree != NULL) {
		BiTreePreOrderTraverse(tree->lchild, Visit);
		Visit(tree->data);
		BiTreePreOrderTraverse(tree->rchild, Visit);
	}
}
void BiTreePostOrderTraverse(BiTree tree, void (*Visit)(ElementType data)) {
	if(tree != NULL) {
		BiTreePreOrderTraverse(tree->lchild, Visit);
		BiTreePreOrderTraverse(tree->rchild, Visit);
		Visit(tree->data);
	}
}
