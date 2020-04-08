#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	int Longest_child(string str1, string str2) {
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		int count = 0;
		int i = 0, j = 0;
		for (int i = 0;i < str1.size();++i) {
			if (str1[i] == str1[i + 1] && i + 1 < str1.size()) {
				continue;
			}
			for (int j = 0;j < str2.size();++j) {
				if (str2[j] == str2[j + 1] && j + 1 < str2.size()) {
					continue;
				}
				if (str1[i] == str2[j]) {
					++count;
				}
			}
		}
		return count;
	}

	int Longest_child2(string str1, string str2) {
		set<char> res;
		for (int i = 0;i < str1.size();++i) {
			size_t pos = 0;
			pos = str2.find(str1[i]);
			if (pos != -1) {
				res.insert(str1[i]);
				str2.erase(pos, 1);
			}
		}
		return res.size();
	}

};

int main() {
	Solution A;
	while (1) {
		string str1, str2;
		cin >> str1 >> str2;
		cout << A.Longest_child2(str1, str2) << endl;
	}
	system("pause");
	return 0;
}