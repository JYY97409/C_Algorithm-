#include"QT.h"

int main()
{
	QT qt1;
	qt1.QTpush(1);
	qt1.QTpush(2);
	qt1.QTpush(3);
	qt1.QTpush(4);
	qt1.QTpush(5);
	qt1.QTpush(6);
	qt1.QTdisplay();
	std::cout << qt1.QTpop() << std::endl;
	std::cout << qt1.QTtail() << std::endl;
	std::cout << qt1.QTfront() << std::endl;
	qt1.QTdisplay();
	return 0;
}