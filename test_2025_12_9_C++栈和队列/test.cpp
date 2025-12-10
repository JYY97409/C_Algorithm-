#include"stack.h"


int main()
{
	ST a(5);
    a.STPush(2);
	std::cout << a.STTop() << std::endl;
	a.STPush(3);
	std::cout << a.STTop() << std::endl;
	a.STPush(4);
	std::cout << a.STTop() << std::endl;
	a.STPush(5);
	std::cout << a.STTop() << std::endl;
	a.STPush(6);
	std::cout << a.STTop() << std::endl;
	a.STPush(7);
	std::cout << a.STTop() << std::endl;
	a.STPop();
	std::cout << a.STTop() << std::endl;
	return 0;
}