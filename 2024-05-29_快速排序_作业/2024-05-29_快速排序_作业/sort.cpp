#include"sort.h"
#include"stack.h"

void PrintfArr(int* arr, int n)
{
	for(int i=0;i<n;i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

//以下都为升序
void Swap(int* p1, int* p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//冒泡排序
void BubbleSort(int* arr, int n)
{
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
		if (0 == flag)
			break;

	}
}
//插入排序
void InsertionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int key = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > key)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = key;
	}
	
}
//三数取中
int GetMidi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[mid] > arr[right])
			return right;
		if (arr[mid] > arr[left])
			return mid;
		if (arr[left] > arr[mid])
			return left;
	}
	if (arr[right] < arr[left])
	{
		if (arr[mid] > arr[left])
			return left;
		if (arr[mid] > arr[right])
			return mid;
		if (arr[right] > arr[mid])
			return right;
	}
	return mid;
}

//霍尔法
int PartSort1(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int key = arr[left];
	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			end--;
		while (begin < end && arr[begin] <= key)
			begin++;
		if(begin<end)
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[left], &arr[begin]);
	return begin;
}

//挖坑法
int PartSort2(int* arr, int left, int right)
{
	int begin = left + 1;
	int end = right;
	int key = arr[left];
	return 1;
}

//前后指针法
int PartSort3(int* arr, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		//这里依旧是没理解
		if (arr[cur] < arr[left] && arr[++prev] >= arr[left])
			Swap(&arr[cur], &arr[prev]);

		cur++;
	}
	Swap(&arr[left], &arr[prev]);
	return prev;
}

//快排主体(递归)
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	/*if (right - left + 1 < 10)
	{
		InsertionSort(arr, right - left + 1);
	}*/
	int mid = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[mid]);
	int key = PartSort3(arr, left, right);

	QuickSort(arr, left, key - 1);
	QuickSort(arr, key + 1, right);
}
//快排主体(非递归)
void QuickSortNonR(int* arr, int left, int right)
{
	stack st1(4);
	st1.StackPush(right);
	st1.StackPush(left);
	int begin = 0;
	int end = 0;
	while (!st1.Isempty())
	{
		begin = st1.StackPop();
		end = st1.StackPop();
		int key = PartSort1(arr,begin, end);
		if (key + 1 < end)
		{
			st1.StackPush(end);
			st1.StackPush(key + 1);
		}
		if (key - 1 > begin)
		{
			st1.StackPush(key - 1);
			st1.StackPush(begin);
		}
		
	}

}