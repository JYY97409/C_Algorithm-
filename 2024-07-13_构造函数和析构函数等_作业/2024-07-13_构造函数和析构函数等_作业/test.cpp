#include"Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month)
{
	int arr[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (2 == month && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;

	return arr[month];
}

Date::Date(int year = 1900, int month = 1, int day = 1)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	int month_day = 0;
	_day += day;
	while (_day > (month_day = GetMonthDay(_year, _month)))
	{
		_day -= month_day;
		_month++;
		if (_month == 13)
		{
			_year += 1;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date temp = *this;
	temp += day;
	return temp;
	//这里是一个临时值，所以要使用值传递，不可以使用引用传递（防止丢数据）
}