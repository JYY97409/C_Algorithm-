//#include<iostream>
//
//class A
//{
//public:
//	void func()
//	{
//		std::cout << "what can i say" << std::endl;
//	}
//
//};
//
//typedef void (A::* PF)();
//
//int main()
//{
//	PF pf;
//	A a;
//	pf = A::func;
//	(a.*pf)();
//	return 0;
//}

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		 _year = year;
		 _month = month;
		 _day = day;
	}
	
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
//private:
	int _year;
	int _month;
	int _day;
};

// 重载为全局的⾯临对象访问私有成员变量的问题
// 有⼏种⽅法可以解决：
// 1、成员放公有
// 2、Date提供getxxx函数
// 3、友元函数
// 4、重载为成员函数
bool operator==(const Date & d1, const Date & d2)
{
	 return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

int main()
{
	Date d1(2024, 7, 5);
	Date d2(2024, 7, 6);
	
	// 运算符重载函数可以显⽰调⽤
	operator==(d1, d2);
	
	// 编译器会转换成 operator==(d1, d2);
	d1 == d2;
	
	int i, j, k;
	i = j = k = 1;//返回值是左操作数
	return 0;
}