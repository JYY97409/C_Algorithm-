#include"Date.h"
#include<iostream>
int main()
{
	Date date1(2006, 12, 23);
	Date date2(2025, 11, 22);
	std::cout << date1 - date2 << std::endl;
	if (date1 != date2)
		std::cout << "date1!=date2" << std::endl;
	if(!(date1 == date2))
		std::cout << "date1!=date2" << std::endl;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1.DisplayDate();
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1.DisplayDate();

	return 0;
}