#include "space_2.h"

parent::parent()
{
	std::cout << "构造 parent"<< std::endl;//构造函数
}

parent::~parent()
{
	std::cout << "~析构 parent" << std::endl;//构造函数
}

void parent::go()
{
	std::cout << "parent go" << std::endl;//构造函数
}

void parent::eat()
{
	std::cout << "parent eat" << std::endl;//构造函数
}

cat::cat()
{
	std::cout << "构造 cat" << std::endl;//构造函数
}

cat::~cat()
{
	std::cout << "~析构 cat" << std::endl;//构造函数
}

void cat::eat()
{
	std::cout << "cat eat" << std::endl;//构造函数
}

void cat::go()
{
	std::cout << "cat go" << std::endl;//构造函数
}

dog::dog()
{
	std::cout << "构造 dog" << std::endl;//构造函数
}

dog::~dog()
{
	std::cout << "~析构 dog" << std::endl;//构造函数
}

void dog::eat()
{
	std::cout << "dog eat" << std::endl;//构造函数
}

void dog::go()
{
	std::cout << "dog go" << std::endl;//构造函数
}
