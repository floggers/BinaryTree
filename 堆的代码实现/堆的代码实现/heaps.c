#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void adjustdowns(int data[], int size,int n) {
	int cur = n;
	while (cur * 2 + 1 < size) {
		if (cur * 2 + 2 >= size) {
			n = cur * 2 + 1;
		}
		else {
			if (data[cur*2+1]>data[cur*2+2]){
				n = cur * 2 + 1;
			}
			else {
				n = cur * 2 + 2;
			}
		}
			if (data[cur]<data[n]){
				int tmp = data[cur];
				data[cur] = data[n];
				data[n] = tmp;
				cur = n;
			}
			else {
				break;;
			}
	}
}

void HeapInits(int data[] , int size) {
	for (int i = size / 2 - 1;i >= 0;i--) {
		adjustdowns(data, size,i);
	}
}

void HeapPops(int data[],int size) {
	if (size == 0) {
		return;
	}
	int tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;
	adjustdowns(data, size-1,0);
}

void HeapSorts(int data[], int size,int m) {
	while (m--) {
		HeapPops(data, size);
		size--;
	}
}