#include<stdio.h>
#include<stdio.h>
#include"binary_tree.h"

void Visit(ElementType data);

void main() {
	BiTree biTree;
	biTree = MakeBiTreeByParent();

	if(!biTree) {
		printf("make tree failed!!\n");
		return;
	}

	printf("pre order traverse: \t");
	BiTreePreOrderTraverse(biTree, Visit);
	printf("\n");

	printf("in order traverse: \t");
	BiTreeInOrderTraverse(biTree, Visit);
	printf("\n");

	printf("post order traverse: \t");
	BiTreePostOrderTraverse(biTree, Visit);
	printf("\n");
	
	printf("broad order traverse: \t");
	BiTreeBroadTraverse(biTree, Visit);
	printf("\n");
}

void Visit(ElementType data) {
	printf("%c", data);
}

