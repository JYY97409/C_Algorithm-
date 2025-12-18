#include"sort.h"

void Swap(DataType* p1, DataType* p2)
{
	DataType temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void DisplayArr(DataType* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertionSort(DataType* arr, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int end = j;
		DataType temp = arr[end + 1];
		while (end >= 0)
		{
			if (temp < arr[end])
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

void Bubblesort(DataType* arr, int n)
{
	DataType temp;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
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
	}
}

void Shellsort(DataType* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			DataType temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
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

void SellctSort(DataType* arr, int n)
{


}


void QuickSort(DataType* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//右边要找的是比key的值小的
	//左边要找的是比key大的
	int key = left;
	int begin = key;
	int end = right;
	int keyi = 0;
	while (end > begin)
	{
		while (end > begin && arr[key] <= arr[end])
		{
			end--;
		}
		while (end > begin && arr[key] >= arr[begin])
		{
 			begin++;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[key], &arr[end]);
	keyi = end;
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);
}
