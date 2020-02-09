#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int high = 0;
		int low = 0;
		int max = nums[0];
		int min = nums[nums.size()-1];
		for (int i = 1;i < nums.size();i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			if (nums[i] < max) {
				high = i;
			}
		}
		for (int i = nums.size()-2;i >= 0;i--) {
			if (nums[i] < min) {
				min = nums[i];
			}
			if (nums[i] > min) {
				low = i;
			}
		}
		sort(nums.begin() + low, nums.begin() + high+1);
		return high - low > 0 ? high - low + 1 : 0;
	}

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

	int getInt(string &s) {
		int ans = 0;
		if (s[0] == '-') {
			for (int i = 1;i < s.size();i++) {
				ans = ans * 10 + s[i] - '0';
			}
			return -ans;
		}
		else {
			for (auto i : s) {
				ans = ans * 10 + i - '0';
			}
			return ans;
		}
	}

	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (auto s : tokens) {
			if ((s[0] >= '0'&&s[0] <= '9') || (s[0] == '-'&&s.size() > 1)) {
				stk.push(getInt(s));
			}
			else {
				int b = stk.top();
				stk.pop();
				int a = stk.top();
				stk.pop();
				stk.push(calc(a, b,s[0]));
			}
		}
		return stk.top();
	}

};

int main() {
	int arr[] = { 2,6,4,8,10,9,16 };
	string str[] = { "2", "1", "+", "3", "*" };
	vector<int> test(arr, arr + 7);
	vector<string> vstr(str, str + 5);
	Solution A;
	//cout << A.findUnsortedSubarray(test);
	cout << A.evalRPN(vstr);
	system("pause");
	return 0;
}