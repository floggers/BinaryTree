#include "stack.h"

void StackInit(Stack* psl, size_t capacity){
	assert(psl);
	psl->capacity = capacity;
	psl->array = (StDataType *)malloc(capacity * sizeof(StDataType));
	assert(psl->array);
	psl->size = 0;
}

void StackDestory(Stack* psl){
	assert(psl);
	if (psl->array){
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(Stack* psl){
	assert(psl);
	if (psl->size == psl->capacity){
		psl->capacity *= 2;
		psl->array = (StDataType *)realloc(psl->array, psl->capacity * sizeof(StDataType));
	}
}

void StackPush(Stack* psl, StDataType x){
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void StackPop(Stack* psl){
	assert(psl || psl->size);
	psl->size--;
}

StDataType StackTop(Stack* psl){
	if (StackIsEmpty(psl)){
		return (StDataType)0;
	}
	return psl->array[psl->size - 1];
}

int StackIsEmpty(Stack* psl){
	return psl->size == 0;
}