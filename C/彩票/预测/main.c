#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int main(void)
{
	unsigned vSrand;
	unsigned in_1, in_2, in_3;
	unsigned re_1, re_2, re_3;
	unsigned nextResult;
	unsigned count= 0; //从第几次开始

	printf("请输入3次结果进行预测！用逗号分隔!\r\n");
	scanf("%u,%u,%u", &in_1, &in_2, &in_3);
	printf("请输入从[多少期]开始预测");
	scanf("%u", &count);

	vSrand = time(0);
	
	do 
	{

		srand(vSrand);
		/*
		* 有可能不是从1期开始的，所以需要指定一个开奖期数
		* 先把前几期的开奖结果跳过，在开始进行匹配。
		*/
		for (int i= count; i > 0; --i)
		{
			printf("skip[%u]\n", rand());
		}

		re_1 = rand();
		re_2 = rand();
		re_3 = rand();

		if ((in_1 == re_1) && (in_2 == re_2) && (in_3 == re_3))
		{
			printf("匹配到关键key[%u]\a", vSrand);
			break;
		}
		else
		{
			printf("测试结果[%u]\n", vSrand);
			continue;
		}
	} while (vSrand--);

	while (1)
	{
		nextResult = rand();
		printf("下一次开奖结果为[%u]", nextResult);
		system("pause");
	}

	return 0;
}