#include"Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month)
{
	int arr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (2 == month && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;

	return arr[month];
}

void Date::DisplayDate()
{
	cout << _year << "->" << _month << "->" << _day << endl;
}

Date::Date(int year, int month, int day)
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

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day < 0)
	{
		_month -= 1;
		if (0 == _month)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year,_month);
		
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date temp = *this;
	temp -= day;
	return temp;
}

Date::~Date() 
{
	
}
//前置++
Date& Date::operator++()
{
	_day++;
	int MonthDay = GetMonthDay(_year, _month);
	if (_day > MonthDay)
	{
		_day -= MonthDay;
		_month++;
	}
	if (13 == _month)
	{
		_month = 1;
		_year++;
	}
	return *this;
}
//后置++
Date Date::operator++(int)
{
	Date temp = *this;
	_day++;
	int MonthDay = GetMonthDay(_year, _month);
	if (_day > MonthDay)
	{
		_day -= MonthDay;
		_month++;
	}
	if (13 == _month)
	{
		_month = 1;
		_year++;
	}
	return temp;
}

Date& Date::operator--()
{
	_day--;
	if (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		int MonthDay = GetMonthDay(_year,_month);
		_day += MonthDay;
	}
	return *this;
}

Date Date::operator--(int)
{
	Date temp = *this;
	_day--;
	if (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		int MonthDay = GetMonthDay(_year, _month);
		_day += MonthDay;
	}
	return temp;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year < d._year)
		return false;
	if (_month > d._month)
		return true;
	if (_month < d._month)
		return false;
	if (_day > d._day)
		return true;


	return false;
}

bool Date::operator==(const Date& d) 
{
	if (_year == d._year);
	else
		return false;
	if (_month == d._month);
	else
		return false;
	if (_day == d._day)
		return true;

	return false;
}

bool Date::operator >= (const Date& d) 
{
	if (_year >= d._year)
		return true;
	else
		return false;
	if (_month >= d._month)
		return true;
	else
		return false;
	if (_day >= d._day)
		return true;


	return false;
}

bool Date::operator < (const Date& d)
{
	if (_year < d._year)
		return true;
	if (_year > d._year)
		return false;
	if (_month < d._month)
		return true;
	if (_month > d._month)
		return false;
	if (_day < d._day)
		return true;


	return false;
}

bool Date::operator <= (const Date& d)
{
	if (_year <= d._year)
		return true;
	else
		return false;
	if (_month <= d._month)
		return true;
	else
		return false;
	if (_day <= d._day)
		return true;


	return false;
}

bool Date::operator != (const Date& d)
{
	if (_year != d._year);
	else
		return false;
	if (_month != d._month);
	else
		return false;
	if (_day != d._day)
		return true;

	return false;
}

int Date::operator-(const Date& d)
{
	Date temp = *this;
	
	temp._year -= d._year;
	temp._month -= d._month;
	temp._day -= d._day;
	int day = 0;

	while (temp._month <= 0)
	{
		temp._year--;
		temp._month += 12;
	}

	while (temp._day <= 0)
	{
		temp._month--;
		while (temp._month <= 0)
		{
			temp._year--;
			temp._month += 12;
		}
		int MonthDay = GetMonthDay(temp._year + d._year, temp._month);
		temp._day += MonthDay;
	}

	if (*this > d)
	{
		day += day;
		for (int i = temp._month + d._month; i > d._month; i--)
		{
			day += GetMonthDay(temp._year + d._year, temp._month);
		}
	}
	else
	{
		day -= day;
		for (int i = temp._month + d._month; i > d._month; i--)
		{
			day -= GetMonthDay(temp._year + d._year, temp._month);
		}
	}
	
	int big = temp._year + d._year;
	int small = d._year;
	if (big < small)
	{
		big = d._year;
		small = temp._year + d._year;
	}


	if (temp._year > 0)
	{
		for (int year = small; year < big; year++)
		{
			if (((year+1) % 4 == 0 && (year+1) % 100 != 0) || (year+1) % 400 == 0)
				day += 366;
			else
				day += 365;
		}

	}
	else
	{
		for (int year = small; year < big; year++)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				day -= 366;
			else
				day -= 365;
		}
	}
	return day;
	
}

