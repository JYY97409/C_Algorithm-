#pragma once
#include<iostream>
#include<cassert>
#include"Tree.h"
typedef BTNode* NodeType;

struct Queuenode
{
	NodeType x;
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

NodeType QueuePop(Queue* qt);

//NodeType Queuesize(Queue* qt);

NodeType QueueFront(Queue* qt);

NodeType QueueTail(Queue* qt);

void QueueDisplayFront(Queue* qt);

void QueueDestory(Queue*& qt);

bool isEmpty(Queue* qt);
