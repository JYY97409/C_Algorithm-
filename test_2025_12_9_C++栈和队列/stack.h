#pragma once
#include<iostream>
#include<cstdlib>

typedef int STDataType;


class ST
{
public:
	ST(int capacity = 4)
	{
		_a = (STDataType*)calloc(capacity , sizeof(STDataType));
		_top = 0;//指向下一个元素
		_capacity = capacity;
	};
	~ST()
	{
		free(_a);
		_a = nullptr;
		
	};
	void STPush( STDataType x)
	{
		if (_top >= _capacity)
		{
			STDataType* pcur = (STDataType*)realloc(_a, (_capacity + 4)*sizeof(STDataType));
			if (pcur == nullptr)
			{
				perror("realloc");
				return ;
			}
			_a = pcur;
			_capacity += 4;
		}
		_a[_top] = x;
		_top++;
	}
	void STPop()
	{
		if (_top > 0)
		{
			_a[--_top] = 0;
		}
		else
		{
			std::cout << "栈是空的" << std::endl;
		}
	}

	STDataType STTop()
	{
		if (_top == 0)
		{
			std::cout << "栈是空的" << std::endl;
			return -1;
		}
		return _a[_top - 1];
	}

	bool STEmpty()
	{
		if (_top == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int STSize()
	{
		return _top - 1;
	}

private:
	STDataType* _a;
	int _top;
	int _capacity;
};


