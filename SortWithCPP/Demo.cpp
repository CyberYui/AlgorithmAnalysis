//测试排序算法
#include <iostream>
#include <stdlib.h>
#include "MyOwnSort.h"
using namespace std;

int main(void)
{
	int size = 10;
	//若从栈中申请数组,要记得使用数组指针作为函数参数
	int *arr = new int[size]{ 5,2,9,3,8,4,0,1,6,7 };
	//BubbleSort(arr, size, true);
	//QuickSort(arr, 0, size - 1);
	//SimpleInsertSort(arr, size);
	ShellSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[]arr;
	arr = NULL;

	system("pause");
	return 0;
}