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

	unsigned count = 0; //�ѿ�������
	srand(time(0));
	do
	{
		system("cls");
		printf("=====��ӭ������ƱС��Ϸ=====\r\n");
		printf("����ǰ���[%u]\r\n", money);
		printf("��ѡ���淨\n[ 1 ]��˫��\n[ 2 ]������\r\n");

		scanf("%u", &mode); //ѡ���淨

		switch (mode)
		{
		case 1: //��˫��
			printf("[ 1 ] ������\n");
			printf("[ 0 ] ����˫��\n");
			winPrice = price_1;
			break;
		case 2: //������
			winPrice = price_2;
			break;
		default:
			printf("���淨û�п��ţ����������룡\r\n");
			system("pause");
			continue;
		}

		printf("������Ҫ�µ�����!\r\n");
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
			printf("��ϲ���н��ˣ��н�����Ϊ[%u],����Ϊ[%u]\n", rNum, winPrice);
		}
		else
		{
			printf("�������Ϊ[%u],���ź�û���н����ٽ�������\n", rNum);
		}
		printf("��ǰ��������[%u]\n", count);
		system("pause");
	} while (1);



	return 0;
}