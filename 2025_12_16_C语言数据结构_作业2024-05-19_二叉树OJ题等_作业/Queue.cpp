#include"Queue.h"


Queue* QueueInit()//队列初始化
{
	Queue* qt = (Queue*)malloc(sizeof(Queue));
	if (qt == nullptr)
	{
		perror("Init");
		return nullptr;
	}
	qt->phead = nullptr;
	qt->ptail = nullptr;
	qt->size = 0;
	return qt;
}

void QueueAdd(Queue* qt, NodeType x)//添加元素
{
	Queuenode* newnode = (Queuenode*)malloc(sizeof(Queuenode));
	if (nullptr == newnode)
	{
		perror("malloc");
		return;
	}
	newnode->next = nullptr;
	if (nullptr == newnode)
	{
		perror("malloc");
		return;
	}
	if (nullptr == qt->phead && nullptr == qt->ptail)
	{
		qt->phead = newnode;
		qt->ptail = newnode;
	}
	else
	{
		qt->ptail->next = newnode;
		qt->ptail = newnode;
	}
	newnode->x = x;
	qt->size++;
}

NodeType QueuePop(Queue* qt)//出元素(带删除)
{
	if (nullptr == qt || nullptr == qt->phead)
	{
		std::cout << "还没有存储数据，无法删除" << std::endl;
		return nullptr;
	}
	NodeType ret;
	if (nullptr == qt->phead->next)
	{
		ret = qt->phead->x;
		free(qt->phead);
		qt->phead = nullptr;
		qt->ptail = nullptr;
	}
	else
	{
		ret = qt->phead->x;
		Queuenode* next = qt->phead->next;
		free(qt->phead);
		qt->phead = next;
	}
	qt->size--;
	return ret;
}

//int Queuesize(Queue* qt)//获得队列的元素数量
//{
//	return qt->size;
//}

NodeType QueueFront(Queue* qt)//读取队列头的函数
{
	assert(qt);
	if (nullptr == qt || nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return nullptr;
	}
	return qt->phead->x;
}

NodeType QueueTail(Queue* qt)//读取队列尾的数据
{
	assert(qt);
	if (nullptr == qt || nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return nullptr;
	}
	return qt->ptail->x;
}

void QueueDisplayFront(Queue* qt)//从头开始展示
{
	if (nullptr == qt)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return;
	}
	Queuenode* pcur = qt->phead;
	while (pcur)
	{
		std::cout << pcur->x << "  ";
		pcur = pcur->next;
	}
	std::cout << std::endl;
}

void QueueDestory(Queue*& qt)//销毁队列
{
	if (nullptr == qt)
	{
		std::cout << "队列为空，无需删除" << std::endl;
		return;
	}
	else if (nullptr == qt->phead)
	{
		std::cout << "队列为空，无需删除" << std::endl;
		return;
	}

	Queuenode* next = nullptr;
	Queuenode* pcur = qt->phead;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(qt);
	qt = nullptr;
}

bool isEmpty(Queue* qt)
{
	if (0 == qt->size)
		return true;
	return false;
}