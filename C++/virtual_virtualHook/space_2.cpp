#include "space_2.h"

parent::parent()
{
	std::cout << "���� parent"<< std::endl;//���캯��
}

parent::~parent()
{
	std::cout << "~���� parent" << std::endl;//���캯��
}

void parent::go()
{
	std::cout << "parent go" << std::endl;//���캯��
}

void parent::eat()
{
	std::cout << "parent eat" << std::endl;//���캯��
}

cat::cat()
{
	std::cout << "���� cat" << std::endl;//���캯��
}

cat::~cat()
{
	std::cout << "~���� cat" << std::endl;//���캯��
}

void cat::eat()
{
	std::cout << "cat eat" << std::endl;//���캯��
}

void cat::go()
{
	std::cout << "cat go" << std::endl;//���캯��
}

dog::dog()
{
	std::cout << "���� dog" << std::endl;//���캯��
}

dog::~dog()
{
	std::cout << "~���� dog" << std::endl;//���캯��
}

void dog::eat()
{
	std::cout << "dog eat" << std::endl;//���캯��
}

void dog::go()
{
	std::cout << "dog go" << std::endl;//���캯��
}
