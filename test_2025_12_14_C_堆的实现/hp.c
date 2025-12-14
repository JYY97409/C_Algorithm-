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

void AdjustDown_s(HpDataType* arr, int size)//向下调整-小堆
{
	int parent = 0;
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
			parent = child;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp_b(HpDataType* arr, int size)//向上调整-大堆
{
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

void AdjustDown_b(HpDataType* arr, int size)//向下调整-大堆
{
	int parent = 0;
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
			parent = child;
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
		AdjustDown_s(hp->arr, hp->size);
		return ret;
	}
}

void DestoryHP(HP* hp)
{
	free(hp->arr);

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
	for (int i = 0; i < size; i++)
	{
		AdjustUp_s(arr, i + 1);
	}
}

void ToBigHP(HpDataType* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		AdjustUp_b(arr, i + 1);
	}
}

void ToUp(HpDataType* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		AdjustUp_b(arr, i + 1);
	}
	//WC了，这里忘记了
	//相当于是将这个数组看成是大堆，每次将一个最大的数放到最后
	while (size > 0)
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		AdjustDown_b(arr, size);
	}
}

void ToDown(HpDataType* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		AdjustUp_s(arr, i + 1);//这里搞错了
	}
	while (size > 0)
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		AdjustDown_s(arr, size);
	}
}