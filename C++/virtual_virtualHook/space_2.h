#pragma once
#include <iostream>

class parent
{
public:
	
	parent();
	~parent();
	virtual void go() ;
	virtual void eat() = 0;
};


class cat :public parent
{
public:
	cat();
	~cat();
	void eat();
	void go();
};


class dog :public parent
{
public:
	dog();
	~dog();
	void eat();
	void go();
};


/*
* ���麯��
* 1. һ������һ���д��麯������ô�����ͳ�Ϊ������
* 2. �����಻��ʵ��������
* 3. ������ͨ����Ϊ����(����)��Ϊ�ӿ���չ
* 4. �̳��������������������д�������еĴ��麯���������������Ҳ���̳�����
* 5. ���������������Ӧ��������������
*/