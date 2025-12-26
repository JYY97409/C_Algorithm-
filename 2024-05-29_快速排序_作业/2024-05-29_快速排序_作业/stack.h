#pragma once
#pragma once
#include<iostream>
typedef int StackType;
class stack
{
private:
	StackType* _arr;
	int _size;
	int _capacity;
public:
	//构造栈
	stack(int n = 4)
	{
		_arr = (StackType*)malloc(sizeof(StackType) * n);
		if (nullptr == _arr)
		{
			perror("malloc fail ");
			return;
		}
		_size = 0;
		_capacity = 4;
	}
	//析构栈
	~stack()
	{
		free(_arr);
	}
	//数据入栈
	void StackPush(StackType val)
	{
		if (_size == _capacity)
		{
			_capacity = _capacity * 2;
			StackType* ret = (StackType*)realloc(_arr, sizeof(StackType) * _capacity);
			if (nullptr == ret)
			{
				perror("realloc fail ");
				return;
			}
			_arr = ret;
		}
		_arr[_size] = val;
		_size++;
	}
	//数据出栈
	StackType StackPop()
	{
		if (Isempty())
		{
			std::cout << "栈是空的" << std::endl;
			return -1;
		}
		StackType ret = _arr[--_size];
		return ret;
	}
	//判空
	bool Isempty()
	{
		if (0 == _size)
			return true;
		return false;
	}
	//返回最后一个元素
	StackType Lastval()
	{
		return _arr[_size - 1];
	}
};
