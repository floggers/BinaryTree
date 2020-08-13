#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool IsValidExp(string s) {
		if (s.empty()) return true;
		int size = s.size();
		if (size % 2) return false;
		int i = 0, j = size - 1;
		bool flag = true;
		while (i < j) {
			if (judge(s[i], s[j])) {
				++i;
				--j;
				continue;
			}
			flag = false;
			break;
		}
		if (!flag) {
			i = 0;
			for (int i = 0;i < size - 1;++i) {
				if (s[i] == '('&&s[i + 1] == ')') {
					++i;
					flag = true;
				}
				else if (s[i] == '['&&s[i + 1] == ']') {
					++i;
					flag = true;
				}
				else if (s[i] == '{'&&s[i + 1] == '}') {
					++i;
					flag = true;
				}
				else {
					flag = false;
				}
			}
		}
		return flag;
	}
	bool judge(char s1, char s2) {
		if (s1 == '('&&s2 == ')') return true;
		else if (s1 == '['&&s2 == ']') return true;
		else if (s1 == '{'&&s2 == '}') return true;
		else {
			return false;
		}
	}

	int GetCoinCount(int N) {
		int left_money = 1024 - N;
		//int max_num = 65535;
		vector<int> coin = { 1,4,16,64 };
		vector<vector<int>> table(4, vector<int>(left_money+1, 0));
		for (int i = 0;i <= left_money;++i) {
			table[0][i] = i;
		}
		for (int i = 0;i < 4;++i) {
			table[i][0] = 0;
		}
		for (int i = 1;i < 4;++i) {
			for (int j = 1;j <= left_money;++j) {
				if (j < coin[i]) {
					table[i][j] = table[i - 1][j];
				}
				else {
					table[i][j] = table[i - 1][j] < table[i][j - coin[i]] + 1 ? table[i - 1][j] : table[i][j - coin[i]] + 1;
				}
			}
		}
		return table[3][left_money];
	}

};

int main() {
	Solution A;
	cout << A.IsValidExp("()[]");
	//cout << A.GetCoinCount(200) << endl;
	system("pause");
	return 0;
}