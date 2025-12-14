#pragma once
#include<iostream>
typedef int HPDataType;
namespace JYY
{
	void Swap(HPDataType* p1, HPDataType* p2)
	{
		HPDataType temp = 0;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	void AdjustUp(HPDataType* hp, int size)
	{
		int child = size - 1;
		int parent = 0;
		while (child > 0)
		{
			parent = (child - 1) / 2;
			if (hp[parent] > hp[child])
			{
				Swap(&hp[parent], &hp[child]);
				child = parent;
			}
			else
			{
				break;
			}
		}
	}
};
class HP
{
private:
	HPDataType* _hp;
	int _size;//此处的size指向的是下一个元素
	int _capacity;
public:
	HP(int capacity = 4)
	{
		_hp = (HPDataType*)malloc(sizeof(HPDataType) * capacity);
		_size = 0;
		_capacity = capacity;
	}
	~HP()
	{
		free(_hp);
	}
	
	
	void HpPush(HPDataType x)
	{
		if (_size == _capacity)//需要扩容
		{
			HPDataType* parr = (HPDataType*)realloc(_hp, _capacity + 4 * sizeof(HPDataType) );
			if (nullptr == parr)
			{
				perror("realloc");
				return;
			}
			_hp = parr;
		}
		_hp[_size] = x;
		_size++;
		JYY::AdjustUp(_hp, _size);
	}
	void HeapifyDown()//向下调整
	{
		int parent = 0;
		int child = 0;
		HPDataType* small = nullptr;
		while (parent * 2 + 1 < _size)//儿子不能超出范围
		{
			child = parent * 2 + 1;
			small = &_hp[child];
			if (_hp[child] > _hp[child + 1])
			{
				small = &_hp[child + 1];
			}
			if (*small < _hp[parent])
			{
				JYY::Swap(&_hp[parent], small);
			}
			parent = child;
		}
	}

	HPDataType HpPop()
	{
		if (0 == _size)
		{
			std::cout << "堆中没有数据" << std::endl;
		}
		else if (1 == _size)
		{
			return _hp[_size--];
		}
		else
		{
			HPDataType ret = _hp[_size - 1];
			JYY::Swap(&_hp[0], &_hp[_size - 1]);
			_size--;//相当于是将最后一个元素排除出去了
			HeapifyDown();
			return ret;
		}

	}

};