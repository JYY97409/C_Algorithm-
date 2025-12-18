#pragma once
#include<iostream>
typedef int DataType;
//交换函数
void Swap(DataType* p1, DataType* p2);
//展示数组
void DisplayArr(DataType* arr, int n);
//插入排序
void InsertionSort(DataType* arr, int n);
//冒泡排序
void Bubblesort(DataType* arr, int n);
//希尔排序
void Shellsort(DataType* arr, int n);
//选择排序
void SellctSort(DataType* arr, int n);
//快速排序
void QuickSort(DataType* arr, int left, int right);