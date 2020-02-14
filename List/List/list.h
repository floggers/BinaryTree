#pragma once
template<class T>
struct ListNode {
		T _data;
		ListNode<T> * _next;
	};

template<class T>
struct SList {
	ListNode<T> * _head;
};

	void ListInit(SList<int> * plist);
	void ListDestroy(SList<int> * plist);
	void ListPushFront(SList<int> * plist, int x);
	void ListPopFront(SList<int> * plist);
	void ListPrint(SList<int> * plist);
	void ListReverse1(SList<int> * plist);      //��ɾͷ�巨  ��ת����
	void ListReverse2(ListNode<int> * plist);     //���ת��    ��ת����