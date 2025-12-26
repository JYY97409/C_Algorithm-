#pragma once
#include<iostream>

//打印数组
void PrintfArr(int* arr, int n);
//交换函数
void Swap(int* p1, int* p2);
//插入排序
void InsertionSort(int* arr, int n);
//冒泡排序
void BubbleSort(int* arr, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);