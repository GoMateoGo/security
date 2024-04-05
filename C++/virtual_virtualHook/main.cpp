#include <iostream>
#include "space_2.h"
#include <string>
#include <Windows.h>


void printHook()
{
    std::cout << "vfptrHook" << std::endl;
}

void test()
{
    // 0x00a1ab5c vfptr
    // vftable 0x00a11541
    // 0 virtual function 0x00291073
    cat* p = new cat;

	/*
	*   ͨ�� ����ָ����ú���
	*   X86�¶���ǰ4���ֽ������ָ��
	* 1. (int*)p ����pת��Ϊ intָ��, �õ�����p�麯����ָ��
	* 2. * (int*)p ȡָ����ָ���ֵ �õ����ĵ�ַ
	* 3. * (int*)*(int*)p ȡ���ĵ�һ��ֵ �õ���һ���麯���ĵ�ַ
	*/

    // 1. ȡ��ַ
    //typedef void(*func)();
    //func f = (func) * (int*)*(int*)p; //�麯���� [0] ��ַ
    //f();
    //f = (func) * ((int*)*(int*)p+1); // �麯����[1] ��ַ ��Ϊ��int����,+1�൱������4���ֽ�
    //f();

    // 2. ͨ��ָ�����
    //int* hook_2 = (int*)*(int*)p;
    //typedef void(*func)();
    //func f = (func)hook_2[0];
    //f();
    //f = (func)hook_2[1];
    //f();



    /*
    *  �麯����Hook
    */
    int* hook = (int*)*(int*)p; // �麯����
    DWORD pOldProtect = 0;
    BOOL isOk = VirtualProtect((void*)hook, sizeof(int), PAGE_EXECUTE_READWRITE, &pOldProtect);
    if (isOk)
    {
        int sFunc = *hook; // ����ԭʼ����ָ��, [0] = go()  [1] = eat()
        *hook = (int)printHook;
        p->go();
        *hook = sFunc;
        p->go();


        sFunc = *(hook + 1);
        *(hook +1)= (int)printHook;
        p->eat();
        *(hook + 1) = sFunc;
        p->eat();
    }

    delete p;
}

int main()
{

    test();

    system("pause");

    return 0;
}