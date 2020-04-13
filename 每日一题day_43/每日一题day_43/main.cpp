#include <iostream>
#include<vector>
#include<string>
#include<set>
#include <algorithm>
using namespace std;

#if 0
int main() {
	int n, m;
	while (cin >> n) {
		cin >> m;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		dp[1][1] = 1;
		for (int i = 2;i <= n;++i) {
			for (int j = 1;j <= m;++j) {
				if (i < j) {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
				}
				else if (i == j) {
					dp[i][j] = dp[i - 1][j] + 1;
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		
	}
	system("pause");
	return 0;
}
#endif

#if 1
int len;
void findSum(int n, int m, int* p,vector<vector<string>> &res) {
	if (m < 1 || n < 1) {
		return;
	}
	if (n > m) {
		n = m;
	}
	if (n == m) {
		p[n - 1] = 1;
		vector<string> buf;
		for (int i = 0;i < len;++i) {
			if (p[i] == 1) {
				buf.push_back(to_string(i + 1));
				buf.push_back(" ");
			}
		}
		buf.pop_back();
		res.push_back(buf);
		p[n - 1] = 0;
	}
	p[n - 1] = 1;
	findSum(n - 1, m - n, p,res);
	p[n - 1] = 0;
	findSum(n - 1, m , p,res);
}

int main() {
	int n, m;
	while (cin >> n) {
		cin >> m;
		vector<vector<string>> res;
		int* p = new int[n];
		len = n;
		findSum(n, m, p,res);
		delete[] p;
		for (auto &i : res) {
			for (auto &e : i) {
				cout << e;
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

#endif

#if 0

int main()
{
	int n, m;
	vector<vector<int>> a;
	vector<int> b;
	while (cin >> n) {
		cin >> m;
		int stateCount = 1 << n;
		for (int i = 0; i < stateCount; ++i)
		{
			for (int j = 0; j < n; ++j)
				if ((1 << j) & i)
					b.push_back(j + 1);
			if (!b.empty())
			{
				a.push_back(b);
			}
			b.clear();
		}
		sort(a.begin(), a.end());
		vector<vector<int>>::iterator it1 = a.begin();
		vector<vector<int>>::iterator it2 = a.end();

		for (;it1 != it2;it1++)
		{
			int sum = 0;
			for (int i = 0;i < (*it1).size();++i)
			{
				sum += (*it1)[i];
			}
			if (sum == m)
			{
				for (int i = 0;i < (*it1).size();++i)
				{
					cout << (*it1)[i] << ' ';
				}
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}
#endif

#if 0
int main() {
	string s;
	int length;
	string NUM = "22233344455566677778889999";
	while (cin >> length){
		set<string> data;
		int cnt;
		for (int i = 0; i < length; i++){
			cnt = 0;
			string res;
			cin >> s;
			for (int j = 0; j < s.length(); j++){
				if (s[j] >= 'A'&&s[j] <= 'Z'){
					res += NUM[s[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (s[j] >= '0'&&s[j] <= '9'){
					res += s[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}
#endif