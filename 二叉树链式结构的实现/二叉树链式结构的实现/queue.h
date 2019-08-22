#pragma once
#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef BTNode* QuDataType;

typedef struct QueueNode {
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue {
	QueueNode* _head;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);
void QueuePush(Queue* plist, QuDataType x);
void QueuetPop(Queue* plist);
int QueueIsEmpty(Queue* plist);
QuDataType QueueTop(Queue* plist);

