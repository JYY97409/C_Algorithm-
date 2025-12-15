#include"hp.h"


HP* HPIint()
{
	HP* hp = (HP*)malloc(sizeof(HP));
	if (NULL == hp)
	{
		perror("malloc");
		return NULL;
	}
	hp->capacity = 4;
	hp->arr = (HpDataType*)malloc(sizeof(HpDataType) * hp->capacity);
	hp->size = 0;
	return hp;
}

void Swap(HpDataType* p1, HpDataType* p2)
{
	HpDataType* temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void AdjustUp_s(HpDataType* arr, int size)//向上调整-小堆
{
	int child = size - 1;
	int parent = 0;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (arr[parent] > arr[child])
		{
			Swap(&arr[parent], &arr[child]);
		}
		child = parent;
	}
}

void AdjustDown_s(HpDataType* arr, int size,int parent)//向下调整-小堆
{
	int child = 0;
	while (parent * 2 + 1 < size)
	{
		child = parent * 2 + 1;
		int small = child;
		if (child + 1 < size && arr[child] > arr[child + 1])
		{
			small = child + 1;
		}

		if (arr[small] < arr[parent])
		{
			Swap(&arr[small], &arr[parent]);
			parent = small;//参数错了，原来是child
		}
		else
		{
			break;
		}
	}
}

void AdjustUp_b(HpDataType* arr, int size)//向上调整-大堆
{
	//这个可以改为
	int child = size - 1;
	int parent = 0;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
		}
		child = parent;
	}
}

void AdjustDown_b(HpDataType* arr, int size,int parent)//向下调整-大堆
{
	int child = 0;
	while (parent * 2 + 1 < size)
	{
		child = parent * 2 + 1;
		int big = child;
		if (child + 1 < size && arr[child] < arr[child + 1])
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

void HPPush(HP* hp, int val)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity += 4;
		HP* ret = realloc(hp->arr, hp->capacity*sizeof(HpDataType));
		if (NULL != ret)
		{
			hp->arr = ret;
		}
	}
	hp->arr[hp->size] = val;
	hp->size++;
	AdjustUp_s(hp->arr,hp->size);
}

HpDataType HPPop(HP* hp)
{
	if (HPIsEmpty(hp))
	{
		printf("\n警告，堆现在是空的\n");
		return -1;
	}
	else
	{
		HpDataType ret = hp->arr[0];
		Swap(&hp->arr[0], &hp->arr[hp->size - 1]);
		hp->size--;//代表被换下的数据已经是失效的了
		AdjustDown_s(hp->arr, hp->size , 0);
		return ret;
	}
}

void DestoryHP(HP* hp)
{
	free(hp->arr);
	free(hp);
}

bool HPIsEmpty(HP* hp)
{
	if (hp->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ToSmallHP(HpDataType* arr, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_s(arr, size, i);
	}
}

void ToBigHP(HpDataType* arr, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_b(arr, size, i);
	}
}

void ToUp(HpDataType* arr, int size)
{
	ToBigHP(arr, size);
	while (size > 0)
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		AdjustDown_b(arr, size, 0);
	}
}

void ToDown(HpDataType* arr, int size)
{
	ToSmallHP(arr, size);
	while (size > 0)
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		AdjustDown_s(arr, size,0);
	}
}

void CreaRanNum()                
{
	FILE* file = NULL;
	fopen_s(&file, "text.txt", "w");
	if (NULL == file)
	{
		perror("fopen_s fail");
		return NULL;
	}
	int n = 10000;
	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%d\n", (rand() + i) % 100000);
	}
	fclose(file);
	file = NULL;
}

void FindMaxK(int k)
{
	FILE* file = NULL;
	fopen_s(&file, "text.txt", "r");
	if (NULL == file)
	{
		perror("fopen_s fail");
		return;
	}
	int ret = 0;
	int* arr = (int*)malloc(sizeof(int) * k);
	if (NULL == arr)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		ret = fscanf_s(file, "%d\n", &arr[i]);
	}
	//输入前k个数据
	ToSmallHP(arr, k);
	//将前k个数据搞成小堆的形式
	int n = 0;
	while ((ret = fscanf_s(file, "%d\n", &n)) > 0)
	{
		if (n > arr[0])
		{
			arr[0] = n;
			AdjustDown_s(arr, k, 0);
		}
	}
	int copy = k;
	while (k > 0)
	{
		Swap(&arr[0], &arr[k - 1]);
		k--;
		AdjustDown_s(arr, k, 0);
	}
	k = copy;
	for (int i = 0; i < k; i++)
	{
		printf("%d  ", arr[i]);
	}
}