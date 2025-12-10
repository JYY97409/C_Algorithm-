#include"Queue.h"


Queue* QueueInit()
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

void QueueAdd(Queue* qt, NodeType x)
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

void QueueDelete(Queue* qt)
{
	if (nullptr == qt || nullptr == qt->phead)
	{
		std::cout << "还没有存储数据，无法删除" << std::endl;
		return;
	}
	if (nullptr == qt->phead->next)
	{
		free(qt->phead);
		qt->phead = nullptr;
		qt->ptail = nullptr;
	}
	else
	{
		Queuenode* next = qt->phead->next;
		free(qt->phead);
		qt->phead = next;
	}
	qt->size--;
}

int Queuesize(Queue* qt)
{
	return qt->size;
}

NodeType QueueFront(Queue* qt)
{
	assert(qt);
	if (nullptr == qt && nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return -1;
	}
	return qt->phead->x;
}

NodeType QueueTail(Queue* qt)
{
	assert(qt);
	if (nullptr == qt && nullptr == qt->phead)
	{
		std::cout << "没有存入数据，无法读取" << std::endl;
		return -1;
	}
	return qt->ptail->x;
}

void QueueDisplayFront(Queue* qt)
{
	if (nullptr == qt )
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

void QueueDestory(Queue* & qt)
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

