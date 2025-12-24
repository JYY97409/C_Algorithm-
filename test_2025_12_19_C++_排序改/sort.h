#pragma once
#include <iostream>
#include "../test_2025_12_22_C++_栈的实现/test_2025_12_22_C++_栈的实现/stack.h"
//交换数据
void Swap(int* p1, int* p2);
//展示数组
void PrintArray(int* arr, int n);
//向下调整算法
void AdjustDown(int* arr, int n, int parent);
//冒泡排序
void BubbleSort(int* arr, int n);
//插入排序
void InsertSort(int* arr, int n);
//希尔排序
void ShellSort(int* arr, int n);
//堆排序
void HeapSort(int* arr, int n);
//选择排序
void SelectSort(int* arr, int n);
//快速排序
void QuickSort(int* arr, int left,int right);
//快速排序
void QuickSortNoRec(int* arr, int left, int right);
//归并排序(递归)
void MergeSort(int* arr, int n);
//归并排序(非递归)
void MergeSortNoRec(int* arr, int n);