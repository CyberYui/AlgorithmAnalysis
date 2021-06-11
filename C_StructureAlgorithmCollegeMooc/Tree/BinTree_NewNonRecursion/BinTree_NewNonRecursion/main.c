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
	printf("输入二叉树的先序序列:");
	bt = CreateBinTree_Recursion();
	printf("该二叉树的先序遍历序列为:");
	//PreOrder_NRecursion1(bt);	//迭代1
	PreOrder_NRecursion2(bt);	//迭代2
	printf("\n");
	printf("该二叉树的中序遍历序列为:");
	InOrder_NRecursion(bt);
	printf("\n");
	printf("该二叉树的后序遍历序列为:");
	PostOrder_NRecursion(bt);
	printf("\n");
	//printf("%d \n",CountSearchNode(bt, ch));
}