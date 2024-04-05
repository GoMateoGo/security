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
* 纯虚函数
* 1. 一个类中一旦有纯虚函数，那么这个类就称为抽象类
* 2. 抽象类不能实例化对象
* 3. 抽象类通常作为基类(父类)作为接口扩展
* 4. 继承这个抽象类的子类必须重写抽象类中的纯虚函数，否则这个子类也会编程抽象类
* 5. 抽象类的析构函数应该是虚析构函数
*/