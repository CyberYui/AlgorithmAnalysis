#ifndef MYOWNSORT_H
#define MYOWNSORT_H
/*****************************************************************************/
/*  项目名称:SwapAddSort
/*  项目描述:交换和排序的相关代码
/*  创建时间:2019-3-18
/*  Author:Cyber Kaka
/*****************************************************************************/

/************************************************************************/
/*	排序算法(分类):
/*		1.非线性时间比较类排序算法:
/*			A.交换排序:	a.冒泡排序
/*							void BubbleSort(int array[])
/*						b.快速排序
/*							void QuickSort(int array[], int start, int last)
/*			B.插入排序:	a.简单插入排序
							void SimpleInsertSort(int array[], int arraySize)
/*						b.希尔排序(缩小增量排序)
							void ShellSort(int array[], int arraySize)
/*			C.选择排序:	a.简单选择排序
/*						b.堆排序
/*			D.归并排序:	a.二路归并排序
/*						b.多路归并排序
/*
/*		2.线性时间非比较类排序算法:
/*			a.基数排序
/*			b.桶排序
/*			c.基数排序
/************************************************************************/

void BubbleSort(int array[], int arraySize, bool bBottomToTop);//冒泡排序

void QuickSort(int array[], int start, int last);//快速排序

void SimpleInsertSort(int array[], int arraySize);//简单插入排序

void ShellSort(int array[], int arraySize);//希尔排序

#endif // MYOWNSORT_H