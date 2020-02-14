#include <iostream>
#include "list.h"
using namespace std;


int main() {
	SList<int> test;
	ListInit(&test);
	ListPushFront(&test, 5);
	ListPushFront(&test, 4);
	ListPushFront(&test, 3);
	ListPushFront(&test, 2);
	ListPushFront(&test, 1);
	ListReverse(&test);
	ListPrint(&test);
	//ListPopFront(&test);
	//ListPrint(&test);
	system("pause");
	return 0;
}