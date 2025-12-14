#pragma once
#include<iostream>
typedef int HPDataType;
namespace JYY
{


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
	HP(HPDataType* arr, int arrsize)
	{
		_hp = (HPDataType*)malloc(sizeof(HPDataType) * arrsize);
		if (nullptr != _hp)
		{
			memcpy(_hp, arr, sizeof(HPDataType) * arrsize);
		}
		_size = arrsize;
		_capacity = arrsize;
		HeapifyUp(arrsize);
	}
	~HP()
	{
		free(_hp);
		_hp = nullptr;
	}
	//通用函数——————————————————————————
	void Swap(HPDataType* p1, HPDataType* p2)
	{
		HPDataType temp = 0;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	void HeapifyUp(int n = 1)
	{
		for (int i = n; i > 0; i--)
		{
			//这里其实是将
			int child = _size - i;
			int parent = 0;
			while (child > 0)
			{
				parent = (child - 1) / 2;
				if (_hp[parent] > _hp[child])
				{
					Swap(&_hp[parent], &_hp[child]);
					child = parent;
				}
				else
				{
					break;
				}
			}
		}
	}
	void HeapifyDownSmall()//向下调整小堆
	{
		int parent = 0;
		int child = 0;
		HPDataType small = 0;
		while (parent * 2 + 1 < _size)//儿子不能超出范围
		{
			child = parent * 2 + 1;
			small = child;
			if (_hp[child] > _hp[child + 1] && child + 1 < _size)//右孩子可能会越界
			{
				small = child + 1;
			}
			if (_hp[small] < _hp[parent])
			{
				Swap(&_hp[parent], &_hp[small]);
				parent = small;
			}
			else
			{
				break;
			}
		}
	}
	void HeapifyDownBig()
	{
		int parent = 0;
		int child = 0;
		HPDataType big = 0;
		while (parent * 2 + 1 < _size)//儿子不能超出范围
		{
			child = parent * 2 + 1;
			big = child;
			if (_hp[child] < _hp[child + 1] && child + 1 < _size)//右孩子可能会越界
			{
				big = child + 1;
			}
			if (_hp[big] > _hp[parent])
			{
				Swap(&_hp[parent], &_hp[big]);
				parent = big;
			}
			else
			{
				break;
			}
		}
	}
	//通用函数————————————————————————
	void DescSort(HPDataType* arr,int size)//降序排序
	{
		int copy = _size;
		while (_size > 0)
		{
			Swap(&_hp[0], &_hp[_size - 1]);
			_size--;
			HeapifyDownSmall();
		}
		_size = copy;
		memcpy(arr, _hp, size*sizeof(HPDataType));
	}

	void AscSort(HPDataType* arr, int size)//升序排序
	{
		int copy = _size;
		while (_size > 0)
		{
			Swap(&_hp[0], &_hp[_size - 1]);
			_size--;
			HeapifyDownBig();
		}
		_size = copy;
		memcpy(arr, _hp, size * sizeof(HPDataType));
	}
	void HpPush(HPDataType x)
	{
		if (_size == _capacity)//需要扩容
		{
			HPDataType* parr = (HPDataType*)realloc(_hp, (_capacity + 4) * sizeof(HPDataType));
			_capacity += 4;
			if (nullptr == parr)
			{
				perror("realloc");
				return;
			}
			_hp = parr;
		}
		_hp[_size] = x;
		_size++;
		HeapifyUp( 1 );
	}

	HPDataType HpPop()
	{
		if (0 == _size)
		{
			std::cout << "堆中没有数据" << std::endl;
		}
		else if (1 == _size)
		{
			return _hp[--_size];
		}
		else
		{
			HPDataType ret = _hp[0];
			Swap(&_hp[0], &_hp[_size - 1]);
			_size--;//相当于是将最后一个元素排除出去了
			HeapifyDownSmall();
			return ret;
		}

	}

	bool IsEmpty()
	{
		if (0 == _size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void EverynNode(int n = 3)
	{
		int i = 0;
		while (i < n && _size>0)
		{
			std::cout << HpPop() << "  " << std::endl;
		}
	}
};

