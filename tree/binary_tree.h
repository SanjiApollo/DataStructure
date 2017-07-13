#ifndef DS_BINARY_TREE_H
#define DS_BINARY_TREE_H

typedef char ElementType;

struct BiTreeNode;
typedef struct BiTreeNode BiTreeNode;
typedef BiTreeNode* BiTree;

void BiTreeAddRoot(BiTree * tree, ElementType data);

// make a binary tree by parent
// data will be given by input stream
// ( character, parent_char, l or r)
BiTree MakeBiTreeByParent();

// make the an empty and return it
BiTree MakeEmpty(BiTree root);

// if the binary tree is not empty, destroy it
void DestoryBiTree(BiTree root);

// clear the bianry tree, free all the nodes
void ClearBiTree(BiTree root);

// return 1 if the binary is empty,
// return 0 if not
int IsBiTreeEmpty(BiTree root);

// get the depth of the binary tree
int GetBiTreeDepth(BiTree root);

// insert 'child' as a child to the 'parent'
// if 'LR' = 0, 'child' will be the left child, 'LR' = 1, will be the right
void BiTreeInsertChild(BiTree root,
		BiTreeNode* parent, int LR, BiTreeNode* child);


BiTreeNode* MakeBiTreeNode(ElementType data);

// preorder traverse
void BiTreePreOrderTraverse(BiTree tree, void (*Visit)(ElementType data));

void BiTreeInOrderTraverse(BiTree tree, void (*Visit)(ElementType data));

void BiTreePostOrderTraverse(BiTree tree, void (*Visit)(ElementType data));

void BiTreeBroadTraverse(BiTree tree, void (*Visit)(ElementType data));

#endif
