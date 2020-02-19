#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#if 0
void reverse(string &src,int begin,int end) {
	while (begin < end) {
		char tmp;
		tmp = src[begin];
		src[begin] = src[end];
		src[end] = tmp;
		begin++;
		end--;
	}
}

int main() {
	string s("123456");
	reverse(s, 0, 5);
	reverse(s, 0, 1);
	reverse(s, 2, 5);
	cout << s;
	system("pause");
	return 0;
}

#endif

#if 1

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		
	}
};

class Solution {
public:
	bool Find(int target, vector<vector<int>> &array) {
		int row = array[0].size();
		int col = array.size();
		for (int i=0;i < row;i++) {
			for (int j=0;j < col;j++) {
				if (target == array[i][j]) {
					return true;
				}
			}
		}
		return false;
	}

	void replaceSpace(char *str, int length) {
		int len = 0;
		int i = 0;
		int space = 0;
		while (str[i]!='\0') {
			if (str[i] == ' ') {
				space++;
			}
			len++;
			i++;
		}
		int newlen = len + 2 * space;
		int p1 = len;
		int p2 = newlen;
		while (p1 <= p2 && p1 >= 0) {
			if (str[p1] == ' ') {
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
			}
			else {
				str[p2--] = str[p1];
			}
			p1--;
		}
	}

	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> buf;
		ListNode* tmp = head->next;
		ListNode* old_head = head;
		while (tmp) {
			old_head->next = tmp->next;
			tmp->next = head;
			head = tmp;
			tmp = old_head->next;
		}
		ListNode* cur;
		for (cur = head;cur;cur = cur->next) {
			buf.push_back(cur->val);
		}
		return buf;
	}

	vector<int> printListFromTailToHead2(ListNode* head) {
		vector<int> buf;
		stack<int> tmp;
		ListNode* cur;
		for (cur = head;cur;cur = cur->next) {
			tmp.push(cur->val);
		}
		while (tmp.size()) {
			buf.push_back(tmp.top());
			tmp.pop();
		}
		return buf;
	}

};

int main() {
	vector<vector<int>> array = { {1,2,3},{4,5,6},{7,8,9} };
	ListNode*head = new ListNode(1);
	ListNode*p2 = new ListNode(2);
	head->next = p2;
	ListNode*p3 = new ListNode(3);
	p2->next = p3;
	ListNode*p4 = new ListNode(4);
	p3->next = p4;
	p4->next = new struct ListNode(5);
	Solution A;
	//cout << A.Find(8, array);
	/*for (auto &i : A.printListFromTailToHead2(head)) {
		cout << i << " ";
	}*/
	char str[50] = " We are family!";
	A.replaceSpace(str, sizeof(str));
	cout << str;
	system("pause");
	return 0;
}

#endif
