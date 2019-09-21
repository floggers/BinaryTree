#include "dequeue.h"

int main(){
	Dequeue test;
	dequeueInit(&test);
	dequeuePush(&test, 1);
	dequeuePush(&test, 2);
	dequeuePush(&test, 3);
	dequeuePop(&test);
	printf("%d ", dequeueFront(&test));
system("pause");
return 0;
}