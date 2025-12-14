#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HpDataType;

typedef struct HP
{
	HpDataType* arr;
	int size;
	int capacity;
}HP;

HP* HPIint();//初始化堆

void DestoryHP(HP* hp);//销毁堆

void HPPush(HP* hp,int val);//向堆中插入数据

void AdjustUp_s(HpDataType* arr, int size);//向上调整

void AdjustDown_s(HpDataType* arr, int size);//向下调整

void AdjustUp_b(HpDataType* arr, int size);//向上调整-大堆

void AdjustDown_b(HpDataType* arr, int size);//向下调整-大堆


void Swap(HpDataType* p1, HpDataType* p2);//交换两个数

HpDataType HPPop(HP* hp);//返回最顶端的数

bool HPIsEmpty(HP* hp);//判断堆是否是空的

void ToSmallHP(HpDataType* arr, int size);//将一个数组转化为小堆

void ToBigHP(HpDataType* arr, int size);//将一个数组转化为大堆

void ToUp(HpDataType* arr, int size);//将一个数组升序排列

void ToDown(HpDataType* arr, int size);//将一个数组降序排列

