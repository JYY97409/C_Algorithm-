#include"Heap.h"
int main()
{
	HPDataType arr[] = { 1,5,3,7,6,9,10,8,2,3,6 };
	class HP hp1(arr,sizeof(arr)/sizeof(HPDataType));
	hp1.DescSort(arr,sizeof(arr)/sizeof(HPDataType));
	/*std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;
	std::cout << hp1.HpPop() << std::endl;*/
	for (int i = 0; i < sizeof(arr) / sizeof(HPDataType);i++)
	{
		std::cout << arr[i] << "  " ;
	}
	hp1.AscSort(arr, sizeof(arr) / sizeof(HPDataType));
	std::cout << std::endl;
	for (int i = 0; i < sizeof(arr) / sizeof(HPDataType); i++)
	{
		std::cout << arr[i] << "  " ;
	}
	return 0;
 }