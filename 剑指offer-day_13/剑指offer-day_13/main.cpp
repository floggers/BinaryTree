#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool compare(string a, string b) {
		if (a.size() == b.size()) {
			return a < b;
		}
		else if (a.size() < b.size()) {
			int len = a.size();
			bool flag = false;
			for (int i = 0;i < len;++i) {
				flag = a[i] < b[i];
				if (flag){
					return true;
				}
			}
			for (int i = len;i < b.size();++i) {
				if (b[i] < a[len - 1]) {
					return false;
				}
			}
			return true;
		}
		else {
			bool flag = false;
			int len = b.size();
			for (int i = 0;i < len;++i) {
				flag = a[i] < b[i];
				if (flag) {
					return true;
				}
			}
			for (int i = len;i < a.size();++i) {
				if (a[i] > b[len - 1]) {
					return false;
				}
			}
			return true;
		}
	}

	string PrintMinNumber(vector<int> numbers) {
		string result;
		vector<string> vstr;
		for (auto &i : numbers) {
			vstr.push_back(to_string(i));
		}
		sort(vstr.begin(), vstr.end(), compare);
		for (auto &i : vstr) {
			result += i;
		}
		return result;
	}

	/*void test() {
		char *str[] = { "32","321","323","3" };
		sort(str, str + 4, compare);
		for (int i = 0;i < 4;++i) {
			cout << str[i];
		}
	}*/
};

int main() {
	Solution A;
	vector<int> v = { 3,1,32,4,2};
	cout << A.PrintMinNumber(v);
	//cout << A.compare("3", "3");
	//A.test();
	system("pause");
	return 0;
}