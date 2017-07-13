#include"../include/utils.h"

#ifndef DS_SQLIST_H
#define DS_SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType * elem;
	int lenght;
	int size;
}SqList;

// init the SqList
Status Init_SqList(SqList &L);
Status Insert_SqList(SqList &L, int i, ElemType e);
Status Delete_SqList(SqList &L, int i, ElemType &e);

Status Init_SqList(SqList &L) {
	L.elem = (ElemType *) malloc(LIST_SIZE*sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
} // Init_Sq

Status Insert_SqList(SqList &L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1) {
		return ERROR;
	}
	if (L.length >= L.size) {
		SqList newbase = (ElemType *) realloc(L.elem,
				(L.size + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.size += LISTINCREMENT;
	}

	q = & (L.elem[i - 1]);
	p = & (L.elem[length - 1]);
	for (; p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	length ++;
	return OK;
} // Insert_SqList

Status Delete_SqList(SqList &L, int i, ElemType e) {
	// 删除第i个元素，并用e返回其值
	if ( i < 1 || i > L.length ) return ERROR;

	p = & (L.elem[i-1]);
	e = *p;
	q = L.elem + L.length -1;
	for ( ++p; p <= q; ++p) {
		*(p - 1) = *p;
	}
	--L.length;
	return OK;
} // Delete_SqList













#endif
