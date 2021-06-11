#include <stdio.h>
#include <stdlib.h>
#include "BinTreeStack.h"
#include "LinkStack.h"

int CountSearchNode(BinTree bt, char ch)
{
	if (bt == NULL)
		return 0;
	if (bt->data == ch)
		return 1;
	return (CountSearchNode(bt->leftchild, ch)) || (CountSearchNode(bt->rightchild, ch));
}

//ABC@@D@@E@FG@@@
void main()
{
	BinTreeNode *bt;
	printf("�������������������:");
	bt = CreateBinTree_Recursion();
	printf("�ö������������������Ϊ:");
	//PreOrder_NRecursion1(bt);	//����1
	PreOrder_NRecursion2(bt);	//����2
	printf("\n");
	printf("�ö������������������Ϊ:");
	InOrder_NRecursion(bt);
	printf("\n");
	printf("�ö������ĺ����������Ϊ:");
	PostOrder_NRecursion(bt);
	printf("\n");
	//printf("%d \n",CountSearchNode(bt, ch));
}