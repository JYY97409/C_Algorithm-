#include"sort.h"

//采用升序排列

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
	//这里的do_while是一个小巧思，当gap==1时可以只进行一次排序,在首个gap
	do
	{
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end = i;
				int temp = arr[end + gap];
				while (end >= j)//这里是一个边界条件，我们应该将预排序视作是划分了一个新的组
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
		gap = gap / 3 + 1;

	} while (gap > 1);
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

void SelectSort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int max = begin, min = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[max] < arr[i])
			{
				max = i;
			}
			if (arr[min] > arr[i])
			{
				min = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		if (begin == max)
			max = min;
		Swap(&arr[end], &arr[max]);

		begin++;
		end--;
	}
}
int GetMidi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] < arr[right] && arr[mid] < arr[right])
	{
		if (arr[left] > arr[mid])
			return left;
		if (arr[mid] > arr[left])
			return mid;
	}
	if (arr[mid] < arr[left] && arr[right] < arr[left])
	{
		if (arr[right] > arr[mid])
			return right;
		if (arr[mid] > arr[right])
			return mid;
	}
	if (arr[left] < arr[mid] && arr[right] < arr[mid])
	{
		if (arr[left] > arr[right])
			return left;
		if (arr[right] > arr[left])
			return right;
	}
	return mid;//默认返回值缺失过
}


int QuickPart1(int* arr, int left, int right)
{
	int key = arr[left];//其实这里的key存值还是存址都行
	int begin = left + 1;
	int end = right;
	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			end--;
		while (begin < end && arr[begin] <= key)
			begin++;
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[left], &arr[begin]);
	return begin;
}

int QuickPart2(int* arr, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[left] && arr[++prev] > arr[left])
			Swap(&arr[cur], &arr[prev]);

		cur++;
	}
	Swap(&arr[left], &arr[prev]);
	return prev;
}

void QuickSort(int* arr, int left,int right)
{
	//left是左第一个下标
	//left.right是闭区间
	if (left >= right)
		return;
	if (right - left < 10)
	{
		InsertSort((arr+left), right - left + 1);
		return;
	}
	int mid = GetMidi(arr, left, right);
	Swap(&arr[left], &arr[mid]);//每次都将mid中间值放到left的位置，是为了利用使用从右边开始数可以保证最后停下来的值是小于key的
	int key = QuickPart2(arr, left, right);
	QuickSort(arr, left, key - 1);
	QuickSort(arr, key + 1 , right);
}


void QuickSortNoRec(int* arr, int left, int right)
{
	//先将右边的数据存进去，读的时候就可先读左边的了
	stack st1;
	st1.StackPush(right);
	st1.StackPush(left);
	while (!st1.Isempty())
	{
		//读取左右区间
		int begin = st1.StackPop();
		int end = st1.StackPop();
		//进行排序
		int key = QuickPart1(arr, begin, end);
		//先将右边的数据存进去
		if (key + 1 < end)
		{
			st1.StackPush(end);
			st1.StackPush(key + 1);
		}
		if (begin < key - 1)
		{
			st1.StackPush(key - 1);
			st1.StackPush(begin);
		}
	}
}

void _MergeSort_(int* arr, int* temp, int left, int right)
{
	if (left == right)
		return;
	//这里我们为啥不先写一个判断条件来判断这个数组是不是有序的呢
	//因为我们在归并的时候无非就是将整个数组分为两半，再遍历一遍，我们这里就没必要脱裤子放屁了

	int mid = (left + right) / 2;
	_MergeSort_(arr, temp, left, mid);
	_MergeSort_(arr, temp, mid + 1, right);

	int begin1 = left,end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while(begin1<=end1&&begin2<=end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[i++] = arr[begin1++];
		else
			temp[i++] = arr[begin2++];
	}
	while (begin1 <= end1)
	{
		temp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = arr[begin2++];
	}
	memcpy((arr + left), (temp+left), (right - left + 1) * sizeof(int));
}

void MergeSort(int* arr, int n)
{
	//我们这里在原数组里直接malloc数组，但是我们不直接使用这个函数递归
	//因为我们如果直接使用原数组递归的话，将会malloc很多次，这是很浪费的
	int* temp = (int*)malloc(sizeof(int) * n);
	if (nullptr == temp)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort_(arr, temp, 0, n - 1);
	free(temp);
}

void MergeSortNoRec(int* arr,int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (nullptr == temp)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		
		for (int i = 0; i < n; i += 2 * gap)//气笑了，少加了个等于号
		{
			//这是个大坑，忘记做备份了
			int j = i;
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + 2 * gap - 1;
			if (begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;
			printf("[%d,%d]  [%d,%d]  ", begin1, end1, begin2, end2);
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
					temp[j++] = arr[begin1++];
				else
					temp[j++] = arr[begin2++];
			}
			while (begin1 <= end1)
			{
				temp[j++] = arr[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[j++] = arr[begin2++];
			}

			memcpy((arr + i), (temp + i),  (end2 - i + 1)* sizeof(int));
		}
		//shgwjinhuhhhjhahhdjhasnhhqwhuiqyjhhuhjdahrqwhduhashdjahjhx
		//wdgfuyasgdfh
		//sahdhhiqnzxjkhui
		gap *= 2;
		printf("\n");
	}
}

