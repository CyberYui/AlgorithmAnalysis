#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkedQueue.h"

//迷宫广度遍历算法
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	//定义方向
	int direction[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
	//两个队列分别保存等待拓展的点的(x,y)值
	LinkedQueue linkQueueX = NULL;
	LinkedQueue linkQueueY = NULL;
	int posX = 0;//临时变量,用于存放x和y
	int posY = 0;
	int preposX = 0;
	int preposY = 0;
	int **preposMarkX;//记录迷宫行走过程中的前序点x值
	int **preposMarkY;//记录迷宫行走过程中的前序点y值
	int **mark;//标记二维数组,不重复走路
	int i = 0;
	int j = 0;
	int mov = 0;
	//给存放前驱x值的数组分配空间
	preposMarkX = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		preposMarkX[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//给存放前驱y值的数组分配空间
	preposMarkY = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		preposMarkY[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//给做标记的二维数组分配空间,并赋初值
	mark = (int **)malloc(sizeof(int*)* maze->size);
	for (i=0;i<maze->size;i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	for (i=0;i<maze->size;i++)//给所有元素设置初值
	{
		for (j=0;j<maze->size;j++)
		{
			preposMarkX[i][j] = -1;
			preposMarkY[i][j] = -1;
			mark[i][j] = 0;
		}
	}
	//创建两个空队列
	linkQueueX = SetNullQueue_Link();
	linkQueueY = SetNullQueue_Link();
	//迷宫入口点入队
	EnQueue_Link(linkQueueX, entryX);
	EnQueue_Link(linkQueueY, entryY);
	//入口点设置标志位
	mark[entryX][entryY] = 1;
	//如果队列不为空且还没有找到迷宫出口点,同样,只需要判断x即可
	while (!IsNullQueue_Link(linkQueueX))
	{
		//取队头元素并出队
		preposX = FrontQueue_Link(linkQueueX);
		DeQueue_Link(linkQueueX);
		preposY = FrontQueue_Link(linkQueueY);
		DeQueue_Link(linkQueueY);
		printf("出队元素是:%d %d\t", preposX, preposY);
		//将与当前点相邻接且满足一定条件的点放入队列中
		for (mov = 0; mov < 8; mov++)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			//如果到达出口点
			if (posX == exitX && posY == exitY)
			{
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
				printf("\n广度搜索迷宫路径如下:\n%d %d\t", posX, posY);
				//将路径逆序输出
				while (!(posX == entryX && posY == entryY))
				{
					//继续往前寻找前驱
					preposX = preposMarkX[posX][posY];
					preposY = preposMarkY[posX][posY];
					posX = preposX;
					posY = preposY;
					printf("%d %d\t", posX, posY);
				}
				return 1;
			}
			//如果能走且没有拓展过
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				//入队拓展
				EnQueue_Link(linkQueueX, posX);
				EnQueue_Link(linkQueueY, posY);
				printf("入队元素是:%d %d\t", posX, posY);
				mark[posX][posY] = 1;//修改标记
				//记录前驱
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
			}
		}
	}
	return 0;
}