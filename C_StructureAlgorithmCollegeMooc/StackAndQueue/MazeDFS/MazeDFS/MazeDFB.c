#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkedQueue.h"

//�Թ���ȱ����㷨
int MazeBFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	//���巽��
	int direction[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
	//�������зֱ𱣴�ȴ���չ�ĵ��(x,y)ֵ
	LinkedQueue linkQueueX = NULL;
	LinkedQueue linkQueueY = NULL;
	int posX = 0;//��ʱ����,���ڴ��x��y
	int posY = 0;
	int preposX = 0;
	int preposY = 0;
	int **preposMarkX;//��¼�Թ����߹����е�ǰ���xֵ
	int **preposMarkY;//��¼�Թ����߹����е�ǰ���yֵ
	int **mark;//��Ƕ�ά����,���ظ���·
	int i = 0;
	int j = 0;
	int mov = 0;
	//�����ǰ��xֵ���������ռ�
	preposMarkX = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		preposMarkX[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//�����ǰ��yֵ���������ռ�
	preposMarkY = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		preposMarkY[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//������ǵĶ�ά�������ռ�,������ֵ
	mark = (int **)malloc(sizeof(int*)* maze->size);
	for (i=0;i<maze->size;i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	for (i=0;i<maze->size;i++)//������Ԫ�����ó�ֵ
	{
		for (j=0;j<maze->size;j++)
		{
			preposMarkX[i][j] = -1;
			preposMarkY[i][j] = -1;
			mark[i][j] = 0;
		}
	}
	//���������ն���
	linkQueueX = SetNullQueue_Link();
	linkQueueY = SetNullQueue_Link();
	//�Թ���ڵ����
	EnQueue_Link(linkQueueX, entryX);
	EnQueue_Link(linkQueueY, entryY);
	//��ڵ����ñ�־λ
	mark[entryX][entryY] = 1;
	//������в�Ϊ���һ�û���ҵ��Թ����ڵ�,ͬ��,ֻ��Ҫ�ж�x����
	while (!IsNullQueue_Link(linkQueueX))
	{
		//ȡ��ͷԪ�ز�����
		preposX = FrontQueue_Link(linkQueueX);
		DeQueue_Link(linkQueueX);
		preposY = FrontQueue_Link(linkQueueY);
		DeQueue_Link(linkQueueY);
		printf("����Ԫ����:%d %d\t", preposX, preposY);
		//���뵱ǰ�����ڽ�������һ�������ĵ���������
		for (mov = 0; mov < 8; mov++)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			//���������ڵ�
			if (posX == exitX && posY == exitY)
			{
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
				printf("\n��������Թ�·������:\n%d %d\t", posX, posY);
				//��·���������
				while (!(posX == entryX && posY == entryY))
				{
					//������ǰѰ��ǰ��
					preposX = preposMarkX[posX][posY];
					preposY = preposMarkY[posX][posY];
					posX = preposX;
					posY = preposY;
					printf("%d %d\t", posX, posY);
				}
				return 1;
			}
			//���������û����չ��
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				//�����չ
				EnQueue_Link(linkQueueX, posX);
				EnQueue_Link(linkQueueY, posY);
				printf("���Ԫ����:%d %d\t", posX, posY);
				mark[posX][posY] = 1;//�޸ı��
				//��¼ǰ��
				preposMarkX[posX][posY] = preposX;
				preposMarkY[posX][posY] = preposY;
			}
		}
	}
	return 0;
}