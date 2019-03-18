#ifndef MYOWNSORT_H
#define MYOWNSORT_H
/*****************************************************************************/
/*  ��Ŀ����:SwapAddSort
/*  ��Ŀ����:�������������ش���
/*  ����ʱ��:2019-3-18
/*  Author:Cyber Kaka
/*****************************************************************************/

/************************************************************************/
/*	�����㷨(����):
/*		1.������ʱ��Ƚ��������㷨:
/*			A.��������:	a.ð������
/*							void BubbleSort(int array[])
/*						b.��������
/*							void QuickSort(int array[], int start, int last)
/*			B.��������:	a.�򵥲�������
							void SimpleInsertSort(int array[], int arraySize)
/*						b.ϣ������(��С��������)
							void ShellSort(int array[], int arraySize)
/*			C.ѡ������:	a.��ѡ������
/*						b.������
/*			D.�鲢����:	a.��·�鲢����
/*						b.��·�鲢����
/*
/*		2.����ʱ��ǱȽ��������㷨:
/*			a.��������
/*			b.Ͱ����
/*			c.��������
/************************************************************************/

void BubbleSort(int array[], int arraySize, bool bBottomToTop);//ð������

void QuickSort(int array[], int start, int last);//��������

void SimpleInsertSort(int array[], int arraySize);//�򵥲�������

void ShellSort(int array[], int arraySize);//ϣ������

#endif // MYOWNSORT_H