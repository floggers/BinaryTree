#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0

int MAX_Cake_num(vector<vector <int>> v,int m,int n) {
	int res = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] == 1) {
				res++;
				if (i + 2 < m) {
					v[i + 2][j] = 0;
				}
				if (j + 2 < n) {
					v[i][j + 2] = 0;
				}
			}
		}
	}
	return res;
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector <int>> v;
	v.resize(H);
	for (int i=0;i < H;i++) {
		v[i].resize(W,1);
	}
	cout << MAX_Cake_num(v, H, W);
	system("pause");
	return 0;
}

#endif

#if 1

class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		int sum = 0;
		if (str.empty()) {
			return 0;
		}
		if (str[0] == '+') {
			flag = 1;
			str[0] = '0';
		}
		if (str[0] == '-') {
			flag = -1;
			str[0] = '0';
		}
			for (int i = 0;i < str.size();i++) {
				if (!isdigit(str[i])){
					sum = 0;
					break;
				}
				sum = sum * 10 + str[i] - 48;
			}
			return sum*flag;
		}
};

int main() {
	Solution A;
	string s1;
	getline(cin, s1);
	cout << A.StrToInt(s1);
	system("pause");
	return 0;
}

#endif