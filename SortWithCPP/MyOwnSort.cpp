#include "MyOwnSort.h"

/****************************************************************/
/* BubbleSort(int array[], int arraySize, bool m_bTopToBottom)	*/
/* 功能:对传入的数组进行冒泡排序,m_bTopToBottom用于判断是从大到	*/
/*		小排列还是从小到大排列									*/
/* 																*/
/*	冒泡排序:													*/
/*	每次比较两个相邻的元素,如果它们的顺序错误就把它们交换过来	*/
/* 																*/
/* 创建日期:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void BubbleSort(int array[], int arraySize, bool bBottomToTop)
{
	int n = arraySize;//获取传入的数组的长度
	if (bBottomToTop == false)
	{
		//从大到小排列
		int i, j;
		for (i = n-1; i >= 0; i--)
		{
			//每一个数都去与每个数比较
			for (j = 0; j <= i; j++)
			{
				//如果左边的数小于右边的数,就交换
				//即使和自己比,也算不满足
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
		//从小到大排列
		int i, j;
		for (i = 1; i <= n - 1; i++)
		{
			//每一个数都去与每个数比较
			for (j = 0; j <= n - i; j++)
			{
				//如果左边的数大于右边的数,就交换
				//即使和自己比,也算不满足
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
/* 功能:快速排序的函数,将指定范围的数组排序						*/
/* 																*/
/* 快速排序:													*/
/* 选择一个枢轴,每次都将数组分为左右两部分,使第一部分小于枢轴,另*/
/* 一部分大于枢轴,随后对两个部分再进行递归地使用快速排序算法	*/
/* 																*/
/* 创建日期:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void QuickSort(int array[], int start, int last)
{
	//如果索引不合法,直接返回
	if (start > last)
	{
		//索引不合法
		return;
	}
	int pivot;	//定义枢轴,作为基准数
	int i, j;	//定义从左和从右找数的哨兵
	int temp;	//定义用于交换数据的临时变量
	pivot = array[start];
	i = start;
	j = last;

	while (i != j)	//当哨兵走到一个地方了就证明找完了
	{
		while (array[j] >= pivot && j > i)
		{
			j--;	//j从右往左找
		}
		while (array[i] <= pivot && i < j)
		{
			i++;	//i从左往右找
		}
		//找到满足的两个数之后,交换哨兵的数据
		if (i<j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	//将枢轴放到应该在的位置
	array[start] = array[i];
	array[i] = pivot;

	QuickSort(array, start, i - 1);	//递归排序枢轴左侧的数组
	QuickSort(array, i + 1, last);	//递归排序数轴右侧的数组
}	


/****************************************************************/
/* SimpleInsertSort(int array[], int arraySize)					*/
/* 功能:对数组进行插入排序										*/
/* 																*/
/* 简单插入排序:												*/
/* 从待排序内容中按索引顺序选择元素,与已经排好序的部分做对比,并	*/
/* 将其插入相应的位置,从而实现对数组的排列						*/
/* 																*/
/* 创建日期:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void SimpleInsertSort(int array[], int arraySize)
{
	for (int i = 1; i < arraySize; i++)
	{
		//先保存当前认为已排好序的数
		int currentElement = array[i];
		int k;
		//与数组内元素逐一比较,决定插入何处
		for (k = i - 1; k >= 0 && array[k] > currentElement; k--)
		{
			//大的往后放
			array[k + 1] = array[k];
		}
		//一旦数组的数小于或等于排好序的数,就把它放当前数前面
		array[k + 1] = currentElement;
	}
}


/****************************************************************/
/* ShellSort(int array[], int arraySize)						*/
/* 功能:对数组进行希尔排序										*/
/*																*/
/* 希尔排序:													*/
/* 把数组按下标的一定规律分组，对每组使用直接插入排序算法排序,随*/
/* 着分组的细化，每组包含的元素越来越多，组数变少,当gap减至1时,	*/
/* 整个文件恰被分成一组，算法随之终止							*/
/* 																*/
/* 创建日期:2019-3-18						Author:Cyber Kaka	*/
/****************************************************************/
void ShellSort(int array[], int arraySize)
{
	//gap作为分组的组数
	for (int gap = arraySize / 2; gap >= 1; gap /= 2)
	{
		//对组进行排序
		for (int i = gap; i < arraySize; i++)
		{
			int temp = array[i];
			int j = i - gap;//j要从离i增量为gap的地方开始
			//当组内的后数比前数小,就交换位置
			while (j >= 0 && temp < array[j])
			{
				array[j + gap] = array[j];
				j -= gap;
			}
			array[j + gap] = temp;
		}
	}
}


/****************************************************************/
/* SlectSort(int array[], int arraySize)						*/
/* 功能:对数组进行简单插入排序									*/
/*																*/
/* 简单插入排序:												*/
/* 假如希望从小到大升序排序数组,则反复地将一个新元素插入到一个已*/
/* 排序的子列表中,直至整个列表排序完毕							*/
/* 																*/
/* 创建日期:2019-3-19						Author:Cyber Kaka	*/
/****************************************************************/
void SlectSort(int array[], int arraySize)
{
	//每次将i个数之后的内容定为已排序内容
	for (int i = arraySize-1; i >=1; i--)
	{
		//定义临时变量保存当前的最大值和最大值下标
		int currentMax = array[0];
		int currentMaxIndex = 0;
		//将每一个array[i]之前的数与其比较
		for (int j = 1; j <= i; j++)
		{
			//一旦找到比array[i]大的数,则将其设定为最大数,保存值和下标
			if (currentMax<array[j])
			{
				currentMax = array[j];
				currentMaxIndex = j;
			}
		}
		//判断最大数是否为array[i],若不是,则将其内容放于最后,即i所在的位置
		if (currentMaxIndex!=i)
		{
			array[currentMaxIndex] = array[i];
			array[i] = currentMax;
		}
	}
}


/****************************************************************/
/* MergeSort(int array[], int arraySize)						*/
/* 功能:对一个数组进行二路归并排序								*/
/*																*/
/* 二路归并排序:												*/
/* 将一个数组划分为两半,对每一半递归地调用归并排序,每当两个子列	*/
/* 表排序完毕,就将它们归并为一个有序的列表,替代之前的父列表,直	*/
/* 到整个数组都完成归并排序										*/
/* 																*/
/* 创建日期:2019-3-19						Author:Cyber Kaka	*/
/****************************************************************/
void merge(int array1[], int array1Size, int array2[], int array2Size, int temp[])
{
	//传入两个数组及其长度,对两者进行二路归并排序,将排好序的内容存入temp[]中

	int current1 = 0;//array1用于循环的索引
	int current2 = 0;//array2用于循环的索引
	int current3 = 0;//用于存放内容的临时数组的索引

	//当对比两个数组的数时,始终把小的存到temp中
	while (current1 < array1Size&&current2 < array2Size)
	{
		if (array1[current1] < array2[current2])
		{
			temp[current3++] = array1[current1++];
		}
		else
		{
			temp[current3++] = array2[current2++];
		}
	}
	//如果只有一个数组时的情况
	while (current1 < array1Size)
	{
		temp[current3++] = array1[current1++];
	}
	while (current2 < array2Size)
	{
		temp[current3++] = array2[current2++];
	}

}

void arraycopy(int source[], int sourceStartIndex, int target[], int targetStartIndex, int length)
{
	//将传入的source数组复制给targe数组
	for (int i = 0; i < length; i++)
	{
		target[i + targetStartIndex] = source[i + sourceStartIndex];
	}

}

void MergeSort(int array[], int arraySize)
{
	//确保传入的数组中至少超过一个数
	if (arraySize>1)
	{
		//将数组分半,第一半下标为从0到arraySize / 2
		int *firstHalf = new int[arraySize / 2];
		arraycopy(array, 0, firstHalf, 0, arraySize / 2);
		MergeSort(firstHalf, arraySize / 2);//对第一个数组归并排序
		//第二半下标为从arraySize/2到arraySize-arraySize/2
		int secondHalfLength = arraySize - arraySize / 2;
		int *secondHalf = new int[secondHalfLength];
		arraycopy(array, arraySize / 2, secondHalf, 0, secondHalfLength);
		MergeSort(secondHalf, secondHalfLength);//对第二个数组归并排序
		//将排序好的结果放给temp数组
		int *temp = new int[arraySize];
		merge(firstHalf, arraySize / 2, secondHalf, secondHalfLength, temp);
		//将temp数组中的内容复制给array,至此,array数组的二路归并排序完成
		arraycopy(temp, 0, array, 0, arraySize);
		delete[]temp;
		delete[]firstHalf;
		delete[]secondHalf;
	}

}