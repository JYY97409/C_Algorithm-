#pragma once
#include<iostream>
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
void SclectSort(int* arr, int n);