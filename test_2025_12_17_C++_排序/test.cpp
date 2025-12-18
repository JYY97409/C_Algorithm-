#include"sort.h"
int main()
{
	DataType arr[] = { 1,5,3,7,8,2,4,9,10 };
	DisplayArr(arr, sizeof(arr) / sizeof(DataType));
	QuickSort(arr,0 ,sizeof(arr) / sizeof(DataType) - 1);
	DisplayArr(arr, sizeof(arr) / sizeof(DataType));

	return 0;
}