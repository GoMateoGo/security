#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int main(void)
{
	unsigned vSrand;
	unsigned in_1, in_2, in_3;
	unsigned re_1, re_2, re_3;
	unsigned nextResult;
	unsigned count= 0; //�ӵڼ��ο�ʼ

	printf("������3�ν������Ԥ�⣡�ö��ŷָ�!\r\n");
	scanf("%u,%u,%u", &in_1, &in_2, &in_3);
	printf("�������[������]��ʼԤ��");
	scanf("%u", &count);

	vSrand = time(0);
	
	do 
	{

		srand(vSrand);
		/*
		* �п��ܲ��Ǵ�1�ڿ�ʼ�ģ�������Ҫָ��һ����������
		* �Ȱ�ǰ���ڵĿ�������������ڿ�ʼ����ƥ�䡣
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
			printf("ƥ�䵽�ؼ�key[%u]\a", vSrand);
			break;
		}
		else
		{
			printf("���Խ��[%u]\n", vSrand);
			continue;
		}
	} while (vSrand--);

	while (1)
	{
		nextResult = rand();
		printf("��һ�ο������Ϊ[%u]", nextResult);
		system("pause");
	}

	return 0;
}