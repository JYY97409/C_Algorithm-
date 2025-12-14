#include"Heap.h"
int main()
{
	class HP hp1;
	hp1.HpPush(1);
	hp1.HpPush(2);
	hp1.HpPush(3);
	hp1.HpPush(4);
	hp1.HpPush(2);
	std::cout << hp1.HpPop() << std::endl;

	return 0;
}