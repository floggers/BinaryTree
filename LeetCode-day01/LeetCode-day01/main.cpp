#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* newList = new ListNode(0);
		queue<int> res;
		int up = 0;
		for (;cur1 || cur2;cur1 = cur1->next, cur2 = cur2->next) {
			if (cur1&&cur2) {
				int tmp = (cur1->val + cur2->val) % 10 + up;
				up = (cur1->val + cur2->val) / 10;
				res.push(tmp);
			}
			else if (cur1) {
				res.push((cur1->val+up)%10);
				up = (cur1->val + up)/10;
			}
			else if (cur2){
				res.push((cur2->val + up) % 10);
				up = (cur2->val + up) / 10;
			}
		}
		if (up) {
			res.push(up);
		}
		int size = res.size()-1;
		newList->val = res.front();
		ListNode*tmp1 = newList;
		res.pop();
		while (size) {
			ListNode* tmp2 = new ListNode(res.front());
			tmp1->next = tmp2;
			tmp1 = tmp2;
			res.pop();
			--size;
		}

		return newList;
	}
};

int main() {

	system("pause");
	return 0;
}