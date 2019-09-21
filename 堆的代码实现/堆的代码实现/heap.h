#ifndef _HEAP_H_
#define _HEAP_H_

typedef int HPDataType;

typedef struct Heap {
	HPDataType* data;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n); 
void HeapDestory(Heap* hp); 
void HeapPush(Heap* hp, HPDataType x); 
void HeapPop(Heap* hp); 
HPDataType HeapTop(Heap* hp); 
int HeapSize(Heap* hp); 
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);
void adjustdown(Heap*hp, int n);
// ∂—≈≈–Ú 
void HeapSort(Heap*hp);

void TestHeap();

/*******************************************/

void adjustdowns(int data[], int size,int n);
void HeapInits(int data[], int size);
void HeapPops(int data[],int size);
void HeapSorts(int data[], int size,int m);
#endif