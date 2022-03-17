#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*******  1.开始游戏  *****\n");
	printf("*******  0.结束游戏  *****\n");
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
		8 * '0';
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{
	
	
		int i = 0;
		int j = 0;
		for (i = -1; i < 2; i++)
		{
			for (j = -1; j < 2; j++)
			{
				if (i != 0 || j != 0)
				{
					if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
					{
						if (mine[x + i][y + j] == '0' && show[x + i][y + j] == '*')
						{
							int count = numMine(mine, x + i, y + j);
							if (count != 0)
							{
								show[x + i][y + j] = count + '0';
								(*win)++;
							}
							else
							{
								show[x + i][y + j] ='0';
								(*win)++;
								expand(mine, show, x + i, y + j, win);
							}
						}
					}
				}
			}
		}
	
}

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col-MINE)
	{
		printf("请输入扫雷坐标：");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{

				printf("这里有地雷，爆炸了！！\n");
				board(mine, ROW, COL);
				break;
			}
			else
			{
				int ret = numMine(mine, x, y);
				if (ret != 0)
				{
					show[x][y] = ret + '0';
					win++;
				}
				else
				{
					show[x][y] = ret + '0';
					win++;
					expand(mine, show, x, y, &win);
				}
				board(show, ROW, COL);
			}
			if (win == row * col - MINE)
				printf("恭喜你，扫雷成功！\n");
			board(mine, ROW, COL);
		}
		else
		{
			printf("坐标超限，请重新输入坐标：\n");
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
	//初始化地图

	setMine(mine, ROW, COL, MINE);//放入地雷
	board(mine, ROW, COL);
	findMine(mine, show, ROW, COL);
}