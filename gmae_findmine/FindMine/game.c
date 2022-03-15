#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*******  1.��ʼ��Ϸ  *****\n");
	printf("*******  0.������Ϸ  *****\n");
	printf("**************************\n");
}

void initboard(char mine[ROWS][COLS], int rows, int cols, char x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = x;
		}
	}
}

void board(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}

void setMine(char mine[ROWS][COLS], int row, int col, int x)
{
	while (x)
	{
		int i = rand() % row+1;
		int j = rand() % col+1;
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (mine[i][j] == '0')
			{
				mine[i][j] = '1';
				x--;
			}
		}
	}
}

int numMine(char mine[ROWS][COLS],  int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] -
		7 * '0';
}

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col-MINE)
	{
		printf("������ɨ�����꣺");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�����е��ף���ը�ˣ���\n");
				board(mine, ROW, COL);
				break;
			}
			else
			{
				show[x][y]=numMine(mine, x, y);
				board(show, ROW, COL);
				win++;
			}
			if (win == row * col - MINE)
				printf("��ϲ�㣬ɨ�׳ɹ���\n");
		}
		else
		{
			printf("���곬�ޣ��������������꣺\n");
		}
	}
}

void game()
{
	char mine[ROWS][COLS] = { '1' };
	char show[ROWS][COLS] = { '#' };
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	board(show, ROW, COL);
	//board(mine, ROW, COL);
	//��ʼ����ͼ

	setMine(mine, ROW, COL, MINE);//�������
	board(mine, ROW, COL);
	findMine(mine, show, ROW, COL);
}