#include "heap.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int _main() {
	int data[10] = { 29,72,48,53,45,30,18,36,15 ,35};
	Heap hp;
	HeapInit(&hp,data,10);
	HeapPrint(&hp);
	HeapSort(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
	system("pause");
	return 0;
}

/****************************************/

int main() {
    int data[] = { 29,72,48,53,45,30,18,36,15 ,35 };
	HeapInits(data, 10);
	int m;
	printf("请输入想要得到第几大的数:");
	scanf("%d", &m);
	HeapSorts(data, 10, m);
	printf("第%d大的数是%d:\n", m, data[10 - m]);
	
		system("pause");
		return 0;
}