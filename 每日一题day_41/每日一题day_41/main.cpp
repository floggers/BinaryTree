#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int calc(int a, int b, char c) {
		if (c == '+') {
			return a + b;
		}
		else if (c == '-') {
			return a - b;
		}
		else if (c == '*') {
			return a*b;
		}
		else {
			return a / b;
		}
	}

	int getInt(string& str) {
		int res = 0;
		if (str[0] == '-') {
			for (int i = 1;i < str.size();++i) {
				res = res * 10 + str[i] - 48;
			}
			return -res;
		}
		else {
			for (auto &i : str) {
				res = res * 10 + i - 48;
			}
			return res;
		}
	}

	int Emacs(vector<string> list) {
		stack<int> stk;
		for (auto &i : list) {
			if ((i[0] >= '0'&&i[0] <= '9') || (i[0] == '-'&&i.size() > 1)) {
				stk.push(getInt(i));
			}
			else {
				int b = stk.top();
				stk.pop();
				int a = stk.top();
				stk.pop();
				stk.push(calc(a, b, i[0]));
			}
		}
		return stk.top();
	}

};


int main() {
	Solution A;
	while (1) {
		int num;
		cin >> num;
		vector<string> vstr(num);
		for (int i = 0;i < num;++i) {
			cin >> vstr[i];
		}
		cout << A.Emacs(vstr) << endl;
	}
	system("pause");
	return 0;
}