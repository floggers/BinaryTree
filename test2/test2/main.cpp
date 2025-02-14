#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode():
		val(),
		next(nullptr){}
};

int main(){
#if 0
	vector<int> star;
	int n;
	for (int i = 0;i < 5;++i) {
		cin >> n;
		star.push_back(n);
	}
	int stars = 0;
	int sum = 0;
	for (int i = 1;i <= 5;++i) {
		stars += star[i - 1] * i;
		sum += star[i - 1];
	}
	float avr;
	if (sum != 0) {
		avr = stars / (sum * 1.0);
		string str = to_string(avr);
		//printf("%0.2f\n", avr);
		for (int i = 0;i < 3;++i) {
			cout << str[i];
		}
		cout << endl;
	}
	else {
		avr = 0.0;
		printf("%0.1f\n", avr);
	}

#endif

#if 0
	int n;
	while (cin >> n) {
		int money = 0;
		vector<int> price;
		for (int i = 0;i < n;++i) {
			int a;
			cin >> a;
			price.push_back(a);
		}
		for (int i = 0;i < price.size();++i) {
			if (i + 1 < price.size() && price[i] == price[i + 1]) {
				++money;
				int tmp = price[i] + 1;
				price[i] = tmp;
				price.erase(price.begin() + i + 1);
				--i;
			}
			else if (i - 1 >= 0 && price[i] == price[i - 1]) {
				++money;
				int tmp = price[i] + 1;
				price[i - 1] = tmp;
				price.erase(price.begin() + i);
				--i;
			}
		}
		cout << money << endl;
	}
#endif
	
#if 0
	unsigned int n = INT_MAX;
	cout << n+1 << endl;

#endif

#if 1
	//��ʼ������
	int a;
	cin >> a;
	ListNode *head = new ListNode();
	ListNode *q, *n;
	head->next = nullptr;
	q = head;
	for (int i = 0;i < a;++i) {
		n = new ListNode();
		cin >> n->val;
		q->next = n;
		n->next = nullptr;
		q = n;
	}
	for (ListNode *cur = head->next;cur;cur = cur->next) {
		cout << cur->val << " ";
	}

#endif

system("pause");
return 0;
}