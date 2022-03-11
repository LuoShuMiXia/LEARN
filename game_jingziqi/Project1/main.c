#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <time.h>
#include<stdlib.h>

int main()
{
	//做一个三子棋游戏
	//打印出来菜单，进行选择,判断开始游戏还是结束游戏
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;


		}
	} while (input);

	return 0;
}