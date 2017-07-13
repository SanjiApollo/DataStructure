#include<stdio.h>
#include"link-list.h"

struct Node {
	ElementType Element;
	Position next;
};

/* Return true if the L is empty */
int
IsEmpty( List L ) {
	return L->Next == NULL;
}

/* Return true if P is the last position in List L */
/* Parameter L is unused in this implementation */
int
IsLast( Position P, List L ) {
	return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position
Find( ElementType X, List L ) {
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X) {
		P = P->Next;
	}

	return P;
}

/* Delete first occurence of X from a list */
/* Assume use of a header node */
void
Delete( ElementType X, List L ) {
	Position P, TmpCell;
	
	P = FindPrevious(X, L);

	if( !IsLast(P, L) ) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

/* if X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position
FindPrevious( ElementType X, List L) {
	Position P;

	P = L;

	while( (P->Next != NULL) && (P->Next->Element != X) ) {
		P = P->Next;
	}

	return P;
}

/* Delete List */
void
DeleteList( List L ) {
	Position P;
	Position TmpCell;

	P = L->Next;
	///////////////////
	L->Next = NULL;
	///////////////////

	while( P != NULL) {
		TmpCell = P;
		P = P->Next;
		free(TmpCell);
	}
}

/* Insert */
void
Insert( ElementType X, List L, Position P ) {
	Position TmpCell;

	TmpCell = (struct Node *) malloc( sizeof(struct Node) );
	if( TmpCell == NULL ) {
		FataError("out of space!!");
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

































