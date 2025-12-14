#include<stdio.h>
#include<string.h>
int main()
{
	int n = 0;
	int temp;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i - 1 - n; j++)
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}