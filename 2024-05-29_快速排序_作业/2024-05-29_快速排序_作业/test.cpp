#include"sort.h"

void TestBullbleSort()
{
	int arr[] = { 6,4,7,8,3,9,10,4,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintfArr(arr, size);
	BubbleSort(arr, size);
	PrintfArr(arr, size);
}

void TestInsertionSort()
{
	int arr[] = { 6,4,7,8,3,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintfArr(arr, size);
	InsertionSort(arr, size);
	PrintfArr(arr, size);
}

void TestQuickSort()
{
	int arr[] = { 6,4,6,2,3,4 ,6,4,6,2,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintfArr(arr, size);
	QuickSort(arr, 0, size - 1);
	PrintfArr(arr, size);
}

void TestQuickSortNonR()
{
	int arr[] = { 6,4,6,2,3,4 ,6,4,6,2,3,4, 6,4,6,2,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintfArr(arr, size);
	QuickSortNonR(arr, 0, size - 1);
	PrintfArr(arr, size);
}

int main()
{
	TestBullbleSort();
	TestInsertionSort();
	TestQuickSort();
	TestQuickSortNonR();
	return 0;
}