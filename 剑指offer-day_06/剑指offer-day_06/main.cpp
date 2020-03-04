#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x,ListNode* p) :
		val(x), next(p) {}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL) {
			return pListHead;
		}
		ListNode* old_head = pListHead;
		ListNode* tmp = old_head->next;
		while (old_head->next) {
			old_head->next = tmp->next;
			tmp->next = pListHead;
			pListHead = tmp;
			tmp = old_head->next;
		}
		ListNode* cur = pListHead;
		for (int i = 1;i < k;++i) {
			cur = cur->next;
		}
		return cur;
	}

	ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
		ListNode* fast= pListHead;
		ListNode* slow = pListHead;
		int i ;
		for ( i = 0;fast != NULL;i++) {
			if (i >= k) {
				slow = slow->next;
			}
			fast = fast->next;
		}
		return i < k ? NULL : slow;
	}

	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL) {
			return pHead;
		}
		ListNode* old_head = pHead;
		ListNode* tmp = old_head->next;
		while (tmp) {
			old_head->next = tmp->next;
			tmp->next = pHead;
			pHead = tmp;
			tmp = old_head->next;
		}
		return pHead;
	}

};

int main() {
	//ListNode* head = new ListNode(1);
	//ListNode* sec = new ListNode(2);
	//ListNode* third = new ListNode(3);
	//ListNode* fourth = new ListNode(4);
	//ListNode* fifth = new ListNode(5);
	//head->next = sec;
	//sec->next = third;
	//third->next = fourth;
	//fourth->next = fifth;
	ListNode list[5] = { {1,&list[1]},{ 2,&list[2] },{ 3,&list[3] },{ 4,&list[4] },{5,NULL} };
	//for (int i = 0;i < 4;++i) {
	//	list[i].val = i + 1;
	//	list[i].next = &list[i + 1];
	//}
	//list[4].val = 5;
	Solution A;
	cout << A.FindKthToTail(&list[0], 2)->val << endl;
	cout << A.ReverseList(&list[0])->val << endl;
	system("pause");
	return 0;
}