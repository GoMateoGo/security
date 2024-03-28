#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

//#define unsigned 

int main(void) {

	unsigned money = 10000;
	unsigned price_1 = 150;
	unsigned price_2 = 5000000;
	unsigned mode = 0;
	unsigned userNum;
	unsigned winPrice = 0;
	_Bool win;
	unsigned rNum;

	unsigned count = 0; //已开奖期数
	srand(time(0));
	do
	{
		system("cls");
		printf("=====欢迎来到彩票小游戏=====\r\n");
		printf("您当前余额[%u]\r\n", money);
		printf("请选择玩法\n[ 1 ]单双数\n[ 2 ]猜数字\r\n");

		scanf("%u", &mode); //选择玩法

		switch (mode)
		{
		case 1: //单双数
			printf("[ 1 ] 代表单数\n");
			printf("[ 0 ] 代表双数\n");
			winPrice = price_1;
			break;
		case 2: //猜数字
			winPrice = price_2;
			break;
		default:
			printf("该玩法没有开放，请重新输入！\r\n");
			system("pause");
			continue;
		}

		printf("请输入要猜的数字!\r\n");
		scanf("%u",&userNum);
		money -= 100;
		win = 0;

		rNum = rand();

		switch (mode)
		{
		case 1:
			win = rNum % 2 == userNum;
			break;
		case 2:
			win = userNum == rNum;
			break;
		default:
			break;
		}
		count++;
		if (win)
		{
			money+= winPrice;
			printf("恭喜您中奖了，中奖数字为[%u],奖金为[%u]\n", rNum, winPrice);
		}
		else
		{
			printf("开奖结果为[%u],很遗憾没有中奖，再接再厉！\n", rNum);
		}
		printf("当前开奖期数[%u]\n", count);
		system("pause");
	} while (1);



	return 0;
}