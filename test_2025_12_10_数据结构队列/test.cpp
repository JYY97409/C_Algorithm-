#include"Queue.h"


int main()
{

	Queue* qt = QueueInit();
	if (nullptr == qt)
	{
		perror("Init");
		return 1;
	}
	QueueAdd(qt, 1);
	QueueAdd(qt, 2);
	QueueAdd(qt, 3);
	QueueAdd(qt, 4);
	QueueAdd(qt, 5);
	QueueDisplayFront(qt);
	QueueDelete(qt);
	QueueDisplayFront(qt);
	QueueDestory(qt);
	QueueDisplayFront(qt);

	return 0;
}