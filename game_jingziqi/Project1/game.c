#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include<stdlib.h>

void menu()
{
	printf("*******************************\n");
	printf("*******  1. ��ʼ��Ϸ  **********\n");
	printf("*******  0. ������Ϸ  **********\n");
	printf("*******************************\n");
}

void InitBoard(char board[ROW][COL],int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("����������������꣺");
		scanf("%d %d", &x, &y);
		if (1 <= x && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�����������\n");
			}
				
		}
		else
		{
			printf("���곬�ޣ�����������\n");
		}
	}
	
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�����������꣺\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
	}
}

int JudgeWinning(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-2; j++)
		{
			if (board[i][j] == '*' && board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j])
				return 1;
			else if (board[i][j] == '#' && board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j])
				return 0;
		}
	}

	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if (board[i][j] == '*' && board[i+1][j] == board[i][j] && board[i+2][j] == board[i][j])
				return 1;
			else if (board[i][j] == '#' && board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j])
				return 0;
		}
	}

	for (i = 0; i < row-2; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == '*' && board[i+1][j + 1] == board[i][j] && board[i+2][j + 2] == board[i][j])
				return 1;
			else if (board[i][j] == '#' && board[i][j + 1] == board[i][j] && board[i][j + 2] == board[i][j])
				return 0;
		}
	}

	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col ; j++)
		{
			if (board[i][j] == ' ' )
				return 3;
		}
	}
	return 4;
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����

	while (1)
	{
		PlayerMove(board,ROW,COL);
		int ret=JudgeWinning(board,ROW,COL);
		switch (ret)
		{
		case 1:
			printf("���ʤ��\n");
			goto FINAL;
		case 2:
			printf("����ʤ��\n");
			goto FINAL;
		case 3:
			break;
		case 4:
			printf("ƽ��");
			goto FINAL;
		}
		DisplayBoard(board, ROW, COL);

		ComputerMove(board, ROW, COL);
		int rst = JudgeWinning(board, ROW, COL);
		switch (rst)
		{
		case 1:
			printf("���ʤ��\n");
			goto FINAL;
		case 2:
			printf("����ʤ��\n");
			goto FINAL;
		case 3:
			break;
		case 4:
			printf("ƽ��");
			goto FINAL;
		}
		DisplayBoard(board, ROW, COL);
	}
	FINAL : DisplayBoard(board, ROW, COL);
}