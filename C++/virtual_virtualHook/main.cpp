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
	*   通过 函数指针调用函数
	*   X86下对象前4个字节是虚表指针
	* 1. (int*)p 对象p转换为 int指针, 得到对象p虚函数表指针
	* 2. * (int*)p 取指针所指向的值 得到虚表的地址
	* 3. * (int*)*(int*)p 取虚表的第一个值 得到第一个虚函数的地址
	*/

    // 1. 取地址
    //typedef void(*func)();
    //func f = (func) * (int*)*(int*)p; //虚函数表 [0] 地址
    //f();
    //f = (func) * ((int*)*(int*)p+1); // 虚函数表[1] 地址 因为是int类型,+1相当于跳过4个字节
    //f();

    // 2. 通过指针调用
    //int* hook_2 = (int*)*(int*)p;
    //typedef void(*func)();
    //func f = (func)hook_2[0];
    //f();
    //f = (func)hook_2[1];
    //f();



    /*
    *  虚函数表Hook
    */
    int* hook = (int*)*(int*)p; // 虚函数表
    DWORD pOldProtect = 0;
    BOOL isOk = VirtualProtect((void*)hook, sizeof(int), PAGE_EXECUTE_READWRITE, &pOldProtect);
    if (isOk)
    {
        int sFunc = *hook; // 保存原始函数指针, [0] = go()  [1] = eat()
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