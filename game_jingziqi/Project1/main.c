#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <time.h>
#include<stdlib.h>

int main()
{
	//��һ����������Ϸ
	//��ӡ�����˵�������ѡ��,�жϿ�ʼ��Ϸ���ǽ�����Ϸ
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;


		}
	} while (input);

	return 0;
}