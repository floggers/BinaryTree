#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void adjustdown(Heap*hp, int n) {                   //向下调整
	int cur = n;
	while (cur * 2 + 1 < hp->size) {               //左孩子还在就继续循坏
		if (cur * 2 + 2 >= hp->size) {             //右孩子不存在 
			n = cur * 2 + 1;
		}
		else {
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2]) {
				n = cur * 2 + 1;
			}
			else {
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n]) {
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;
		}
		else {
			break;
		}
	}
}


void HeapInit(Heap* hp, HPDataType* a, int n) {
	hp->capacity = 2 * n;
	hp->size = n;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(hp->size));
	for (int i = 0;i < hp->size;i++) {
		hp->data[i] = a[i];
	}
	for (int i = n / 2 - 1;i >= 0;i--) {                  // n/2-1 :最后一个非叶子节点的下标
	adjustdown(hp, i);
	}
}


void HeapPush(Heap* hp, HPDataType x) {
	if (hp->size==hp->capacity){
		hp->data = (HPDataType*)realloc(hp->data,hp->capacity*2 );  
	}
	int cur = hp->size;
	hp->data[hp->size] = x;
	hp->size++;
	while (cur > 0) {                                       //向上调整
		if (hp->data[cur] > hp->data[(cur - 1) / 2]) {
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPop(Heap* hp) {
	if (hp->size==0){
		return;
	}
	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;
	adjustdown(hp, 0);
}

void HeapSort(Heap* hp) {
	int tmp = hp->size;
	while (hp->size > 1) {
		HeapPop(hp);
	}
	hp->size = tmp;
}

HPDataType HeapTop(Heap* hp) {
	if (hp->size==0){
		return (HPDataType)0;
	}
	return hp->data[0];
}

int HeapSize(Heap* hp) {
	return hp->size;
}

void HeapDestory(Heap* hp) {
	if (hp->data) {
		free(hp->data);
	}
	hp->data = NULL;
	free(hp->data);
}

void HeapPrint(Heap* hp) {
	int rn = 0;
	int bin = 2;
	for (int i = 0;i < hp->size;i++) {
		printf("%d  ", hp->data[i]);
		if (i == rn) {
			putchar('\n');
			rn += bin;
			bin = bin * 2;
		}
	}
	putchar('\n');
}