#pragma once
#include<iostream>
typedef int TypeNode;

struct QTNode//基本节点
{
	TypeNode _val;
	struct QTNode* next;
};

class QT
{
public:
	QT()//构造函数
	{
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}
	~QT()//析构函数
	{
		QTNode* cur = _head;
		QTNode* next = nullptr;
		while (cur)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
	}
	void QTpush(TypeNode val)//入队列
	{
		QTNode* NewNode = (QTNode*)malloc(sizeof(QTNode));
		if (nullptr == NewNode)
		{
			perror("malloc");
			return;
		}
		NewNode->next = nullptr;
		NewNode->_val = val;
		if (nullptr == _head && nullptr == _tail)
		{
			_head = _tail = NewNode;
			_head->next = nullptr;
			_tail->next = nullptr;
		}
		else
		{
			_tail->next = NewNode;
			_tail = NewNode;
			_tail->next = nullptr;
		}
		_size++;
	}
	TypeNode QTpop()//出队列
	{
		if (nullptr == _tail && nullptr==_head)
		{
			std::cout << "当前队列中没有数据" << std::endl;
			return -1;
		}
		else
		{
			TypeNode ret;
			if (nullptr == _tail)
			{
				std::cout << "当前队列中没有数据" << std::endl;
				return -1;
			}
			else if (_head == _tail)
			{
				ret = _head->_val;
				free(_head);
				_head = _tail = nullptr;
			}
			else
			{
				ret = _tail->_val;
				QTNode* cur = _head;
				while (cur->next != _tail)
				{
					cur = cur->next;
				}
				free(_tail);
				_tail = nullptr;
				_tail = cur;
				_tail->next = nullptr;
			}
			_size--;
			return ret;
		}	
	}
	TypeNode QTtail()//取头元素
	{
		TypeNode ret;
		if (nullptr == _tail && nullptr == _head && _size == 0)
		{
			std::cout << "当前队列中没有数据" << std::endl;
			return -1;
		}
		else
		{
			if (nullptr == _tail)
			{
				ret = -1;
			}
			else
			{
				ret = _tail->_val;
			}
		}
		return ret;
	}
	TypeNode QTfront()//取尾元素
	{
		TypeNode ret;
		if (nullptr == _tail && nullptr == _head && 0 == _size)
		{
			std::cout << "当前队列中没有数据" << std::endl;
			return -1;
		}
		else
		{
			if (nullptr == _head)
			{
				ret = -1;
			}
			else
			{
				ret = _head->_val;
			}
		}
		return ret;
	}
	void QTdisplay()//展示全部节点数据
	{
		if (nullptr == _head && nullptr == _tail)
		{
			std::cout << "当前队列中没有数据" << std::endl;
			return;
		}
		else
		{
			QTNode* cur = _head;
			while (cur)
			{
				std::cout << cur->_val << "  ";
				cur = cur->next;
			}
			std::cout << std::endl;
		}
	}
private:
	QTNode* _head;
	QTNode* _tail;
	int _size;
};