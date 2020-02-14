#include <iostream>
#include "list.h"
using namespace std;

void ListInit(SList<int> * plist) {
	plist->_head = nullptr;
}

void ListDestroy(SList<int> * plist) {
	ListNode<int> * tmp;
	while (plist->_head) {
		tmp = plist->_head;
		plist->_head = tmp->_next;
		delete tmp;
	}
}

void ListPushFront(SList<int> * plist, int x) {            //头插
	ListNode<int> * cur = new ListNode<int>;
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void ListPopFront(SList<int> * plist) {
	if (plist->_head) {
		ListNode<int> * tmp = plist->_head;
		plist->_head = tmp->_next;
		delete tmp;
	}
}

void ListPrint(SList<int> * plist) {
	ListNode<int> * cur;
	for (cur = plist->_head;cur;cur = cur->_next) {
		cout << cur->_data << "->";
	}
	cout << "nullptr" << endl;
}

void ListReverse1(SList<int> * plist) {                    //后删头插法
	ListNode<int> * old_head = plist->_head;
	ListNode<int> * tmp = plist->_head->_next;
	while (tmp) {
		old_head->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
		tmp = old_head->_next;
	}
}

void ListReverse2(ListNode<int> * pHead) {                  //向后转法
	ListNode<int> * cur = pHead;
	ListNode<int> * pre = nullptr;
	while (cur) {
		ListNode<int> * tmp = cur->_next;
		cur->_next = pre;
		pre = cur;
		cur = tmp;
	}
}