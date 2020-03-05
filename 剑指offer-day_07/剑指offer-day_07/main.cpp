#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x = 0,ListNode* p = NULL) :
		val(x), next(p) {}
};

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {              //�ǵݹ�д��
	    if (pHead2 == NULL || pHead1 == NULL) {
			return pHead1 ? pHead1 : pHead2;
		}
		ListNode* p1 = pHead1->val <= pHead2->val ? pHead1 : pHead2;
		ListNode* p2 = pHead1->val > pHead2->val ? pHead1 : pHead2;
		ListNode* pMergeHead = NULL; buf = pHead1->val <= pHead2->val ? pHead1 : pHead2;   //�ϲ������ͷָ��
		ListNode* spe = NULL;        //��¼p1ָ���λ��
		while (p1 && p2) {          //����һ��ָ��ָ���ʱ ��ѭ���˳�
			if (p1->next != NULL  && p1->next->val >= p2->val) {
				ListNode* tmp = p1->next;
				ListNode* tmp1 = p2->next;
				p1->next = p2;
				p2->next = tmp;
				p1 = p1->next;
				p2 = tmp1;
			}
			else {
				spe = p1;          //ÿ�μ�¼p1ָ���λ�� ��ָֹ���  Ӱ����һ������
				p1 = p1->next;	
			}
		}
		if (p1 == NULL) {         //��p1ָ���ʱ  ��ôspe����p1��һ����ָ��  ����ָ��ָ��p2������������������
			spe->next = p2;
		}
		return pMergeHead;
	}

	ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {             //�ݹ�д��
		if (!pHead1) {
			return pHead2;
		}
		else if (!pHead2) {
			return pHead1;
		}
		ListNode* pMergeHead = nullptr;
		if (pHead1->val <= pHead2->val) {
			pMergeHead = pHead1;
			pMergeHead->next = Merge1(pHead1->next, pHead2);
		}
		if (pHead1->val > pHead2->val) {
			pMergeHead = pHead2;
			pMergeHead->next = Merge1(pHead1, pHead2->next);
		}
		return pMergeHead;
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1 == nullptr || pRoot2 == nullptr) {
			return false;
		}
		return
			isSubTree(pRoot1, pRoot2) ||
			HasSubtree(pRoot1->left, pRoot2) ||
			HasSubtree(pRoot1->right, pRoot2);
				
	}


	bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
		// B���������ˣ�˵��B��A���ӽṹ
		if (!pRoot2) {
			return true;
		}
		// A�������ˣ�����B��û�б����꣬��ôB�϶�����A���ӽṹ
		if (!pRoot1) {
			return false;
		}

		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return
			isSubTree(pRoot1->left, pRoot2->left) &&
			isSubTree(pRoot1->right, pRoot2->right);
	}

};

int main() {
	ListNode list1[5] = { { 1,&list1[1] },{ 3,&list1[2] },{ 3,&list1[3] },{ 7,&list1[4] },{ 8,NULL } };
	ListNode list2[5] = { { 1,&list2[1] },{ 2,&list2[2] },{ 4,&list2[3] },{ 4,&list2[4] },{ 9,NULL } };
	//ListNode list2[] = { NULL };
	//ListNode list1[] = { NULL };
	Solution A;
	ListNode* cur = A.Merge1(list1, list2);
	for (;cur;cur = cur->next) {
		cout << cur->val << "  ";
	}
	system("pause");
	return 0;
}