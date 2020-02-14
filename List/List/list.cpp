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

void ListPushFront(SList<int> * plist, int x) {            //Í·²å
	ListNode<int> * cur = new ListNode<int>();
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

void ListReverse(SList<int> * plist) {
	ListNode<int> * old_head = plist->_head;
	ListNode<int> * tmp = plist->_head->_next;
	while (tmp) {
		old_head->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
		tmp = old_head->_next;
	}
}