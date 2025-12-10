#pragma once
#include<iostream>
#include<cassert>
typedef int NodeType;

struct Queuenode
{
	int x;
	Queuenode* next;
};

struct Queue
{
	Queuenode* phead;
	Queuenode* ptail;
	int size = 0;
};

Queue* QueueInit();

void QueueAdd(Queue* qt, NodeType x);

void QueueDelete(Queue* qt);

NodeType Queuesize(Queue* qt);

NodeType QueueFront(Queue* qt);

NodeType QueueTail(Queue* qt);

void QueueDisplayFront(Queue* qt);

void QueueDestory(Queue* & qt);