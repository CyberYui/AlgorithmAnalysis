#include "MyOwnSort.h"

/****************************************************************/
/* BubbleSort(int array[], int arraySize, bool m_bTopToBottom)	*/
/* ����:�Դ�����������ð������,m_bTopToBottom�����ж��ǴӴ�	*/
/*		С���л��Ǵ�С��������									*/
/* 																*/
/*	ð������:													*/
/*	ÿ�αȽ��������ڵ�Ԫ��,������ǵ�˳�����Ͱ����ǽ�������	*/
/* 																*/
/* ��������:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void BubbleSort(int array[], int arraySize, bool bBottomToTop)
{
	int n = arraySize;//��ȡ���������ĳ���
	if (bBottomToTop == false)
	{
		//�Ӵ�С����
		int i, j;
		for (i = n-1; i >= 0; i--)
		{
			//ÿһ������ȥ��ÿ�����Ƚ�
			for (j = 0; j <= i; j++)
			{
				//�����ߵ���С���ұߵ���,�ͽ���
				//��ʹ���Լ���,Ҳ�㲻����
				if (array[j] < array[j + 1])
				{
					int temp = array[j];
					array[j] = array[j+1];
					array[j + 1] = temp;
				}
			}
		}
	}
	else if (bBottomToTop == true)
	{
		//��С��������
		int i, j;
		for (i = 1; i <= n - 1; i++)
		{
			//ÿһ������ȥ��ÿ�����Ƚ�
			for (j = 0; j <= n - i; j++)
			{
				//�����ߵ��������ұߵ���,�ͽ���
				//��ʹ���Լ���,Ҳ�㲻����
				if (array[j - 1] > array[j])
				{
					int temp = array[j - 1];
					array[j - 1] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	return;
}


/****************************************************************/
/* QuickSort(int array[], int start, int last)					*/
/* ����:��������ĺ���,��ָ����Χ����������						*/
/* 																*/
/* ��������:													*/
/* ѡ��һ������,ÿ�ζ��������Ϊ����������,ʹ��һ����С������,��*/
/* һ���ִ�������,�������������ٽ��еݹ��ʹ�ÿ��������㷨	*/
/* 																*/
/* ��������:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void QuickSort(int array[], int start, int last)
{
	//����������Ϸ�,ֱ�ӷ���
	if (start > last)
	{
		//�������Ϸ�
		return;
	}
	int pivot;	//��������,��Ϊ��׼��
	int i, j;	//�������ʹ����������ڱ�
	int temp;	//�������ڽ������ݵ���ʱ����
	pivot = array[start];
	i = start;
	j = last;

	while (i != j)	//���ڱ��ߵ�һ���ط��˾�֤��������
	{
		while (array[j] >= pivot && j > i)
		{
			j--;	//j����������
		}
		while (array[i] <= pivot && i < j)
		{
			i++;	//i����������
		}
		//�ҵ������������֮��,�����ڱ�������
		if (i<j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	//������ŵ�Ӧ���ڵ�λ��
	array[start] = array[i];
	array[i] = pivot;

	QuickSort(array, start, i - 1);	//�ݹ�����������������
	QuickSort(array, i + 1, last);	//�ݹ����������Ҳ������
}	


/****************************************************************/
/* SimpleInsertSort(int array[], int arraySize)					*/
/* ����:��������в�������										*/
/* 																*/
/* �򵥲�������:												*/
/* �Ӵ����������а�����˳��ѡ��Ԫ��,���Ѿ��ź���Ĳ������Ա�,��	*/
/* ���������Ӧ��λ��,�Ӷ�ʵ�ֶ����������						*/
/* 																*/
/* ��������:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void SimpleInsertSort(int array[], int arraySize)
{
	for (int i = 1; i < arraySize; i++)
	{
		//�ȱ��浱ǰ��Ϊ���ź������
		int currentElement = array[i];
		int k;
		//��������Ԫ����һ�Ƚ�,��������δ�
		for (k = i - 1; k >= 0 && array[k] > currentElement; k--)
		{
			//��������
			array[k + 1] = array[k];
		}
		//һ���������С�ڻ�����ź������,�Ͱ����ŵ�ǰ��ǰ��
		array[k + 1] = currentElement;
	}
}


/****************************************************************/
/* FunName()													*/
/* ����:														*/
/*																*/
/* 																*/
/* ��������:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void ShellSort(int array[], int arraySize)
{

}