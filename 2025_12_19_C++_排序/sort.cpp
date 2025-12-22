#include"sort.h"

//²ÉÓÃÉıĞòÅÅÁĞ

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void BubbleSort(int* arr, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
	}
}

void AdjustDown(int* arr, int n, int parent)
{
	int big = 0;
	int child =0;
	while (parent * 2 + 1 < n)
	{
		child = parent * 2 + 1;
		big = child;
		if (child + 1 < n && arr[child + 1] > arr[child]) 
		{
			big = child + 1;
		}
		if (arr[big] > arr[parent])
		{
			Swap(&arr[big], &arr[parent]);
			parent = big;
		}
		else
		{
			break;
		}
	}
}

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = temp;
	}
}

void ShellSort(int* arr, int n)
{
	int gap = n / 3 + 1;
	while (gap != 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end = i;
				int temp = arr[end + gap];
				while (end >= 0)
				{
					if (arr[end] > temp)
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				arr[end + gap] = temp;
			}

		}
	}
}

void HeapSort(int* arr, int n)
{ 
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0)
	{
		AdjustDown(arr, n, parent);
		parent--;
	}
	while (n > 1)
	{
		Swap(&arr[0], &arr[n - 1]);
		n--;
		AdjustDown(arr, n, 0);
	}
}


void SclectSort(int* arr, int n)
{
	
}

