#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
	stack<int> _stack;
	stack<int> _stack_little;
public:
	void push(int value) {
		if (_stack.empty()) {
			_stack.push(value);
		}
		if (_stack_little.empty()) {
			_stack_little.push(value);
		}
		else if (value <= _stack_little.top()) {
			_stack_little.push(value);
		}
			_stack.push(value);
	}
	void pop() {
		if (_stack.empty()) {
			return;
		}
		if (_stack.top() == _stack_little.top()) {
			_stack.pop();
			_stack_little.pop();
		}
		else {
			_stack.pop();
		}
	}
	int top() {
		if (!_stack.empty()) {
				return _stack.top();
		}
	}
	int min() {
		if (!_stack_little.empty()) {
			return _stack_little.top();
		}
	}

	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> buf;
		for (int i = 0;i < pushV.size();++i) {
			buf.push(pushV[i]);
			while (!buf.empty() && popV[0] == buf.top()) {
				buf.pop();
				popV.erase(popV.begin());
			}
		}
		return buf.empty();
	}
};

int main() {
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int>v2 = { 4,5,3,2,1 };
	Solution A;
	cout << A.IsPopOrder(v1, v2);
	system("pause");
	return 0;
}