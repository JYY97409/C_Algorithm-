#include"hp.h"
int main()
{
	srand((unsigned int)time);
	
	/*HP* hp = HPIint();
	HPPush(hp, 1);
	HPPush(hp, 7);
	HPPush(hp, 4);
	HPPush(hp, 5);
	HPPush(hp, 3);
	HPPush(hp, 9);
	HPPush(hp, 8);
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	printf("%d  ", HPPop(hp));
	DestoryHP(hp);
	HpDataType arr[] = {3,5,2,6,7,10,9,8,7,6,5,4,8};
	int arrsize = sizeof(arr) / sizeof(HpDataType);
	ToSmallHP(arr, arrsize);
	HpDataType arr1[] = { 3,4,2,5,7,10,8,9,6,5,4};
	int arr1size = sizeof(arr1) / sizeof(HpDataType);
	ToDown(arr1,arr1size);
	printf("\n");
	for (int i = 0; i < arr1size; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	ToUp(arr1, arr1size);
	for (int i = 0; i < arr1size; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");*/

	//ÒÔÉÏÊÇ²âÊÔ¶ÑºÍ¶ÑÅÅÐò----------------------------
	int k = 0;
	printf("ÇëÊäÈëk\n");
	scanf_s("%d", &k);
	FindMaxK(k);
	/*CreaRanNum();*/

	return 0;
}