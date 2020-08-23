#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKth(ListNode* pListHead, int k) {
		//ListNode* fast = pListHead;
		ListNode* tmp = pListHead;
		ListNode* q = pListHead;
		ListNode* p = NULL;
		for (int i = 0;q != NULL,i < k-1 ;i++) {
			p = q;
			q = q->next;
		}
		p->next = q->next;
		return  tmp;
	}

	int BestVal(int num) {
		int res = 0;
		for (int i = 0;i <= num;++i) {
			int left = num - i;
			int tmp = help(i, left);
			res = res > tmp ? res : tmp;
		}
		return res;
	}

	int help(int num1, int num2) {
		int sum = 0;
		while (num1) {
			sum += num1 % 10;
			num1 /= 10;
		}
		while (num2) {
			sum += num2 % 10;
			num2 /= 10;
		}
		return sum;
	}

	bool isRightString(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			++i;
			--j;
		}
		return true;
	}

	int HowManyStrings(string s,int l,int r) {
		int res = 0;
		string buf = s.substr(l - 1, r - 1);
		if (isRightString(buf)) {
			res = 1;
			return res;
		}
		for (int i = 0;i < buf.size();++i) {
			string buf1 = buf.substr(0, i);
			string buf2 = buf.substr(i + 1);
			if (isRightString(buf1) && isRightString(buf2)) {
				res = 2;
				return res;
			}
		}
		return s.size();
	}

};


int main() {
	Solution A;
	string s;
	while (getline(cin, s)) {
		int Q;
		cin >> Q;
		vector<vector<int>> buf;
		vector<int> tobuf;
		while (Q) {
			int num1, num2;
			cin >> num1 >> num2;
			tobuf.push_back(num1);
			tobuf.push_back(num2);
			buf.push_back(tobuf);
			--Q;
		}
		for (int i = 0;i < Q;++i) {
			int num = A.HowManyStrings(s, buf[i][0], buf[i][1]);
			cout << num << endl;
		}
	}

	/*int T, n;
	while (cin >> T) {
		for (int i = 0;i < T;++i) {
			cin >> n;
			int res = A.BestVal(n);
			cout << res << endl;
		}
	}*/

	//while (cin >> n >> k) {
	//	ListNode* pListHead, *p, *q;
	//	pListHead = new ListNode(NULL);
	//	pListHead->next = NULL;
	//	q = pListHead;
	//	for (int i = 0;i < n;++i) {
	//		p = new ListNode(NULL);
	//		cin >> p->val;
	//		p->next = NULL;
	//		q->next = p;
	//		q = p;
	//	}
	//	ListNode* res = A.FindKth(pListHead->next, k);
	//	for (res;res;res = res->next) {
	//		cout << res->val << " ";
	//	}
	//}
	system("pause");
	return 0;
}