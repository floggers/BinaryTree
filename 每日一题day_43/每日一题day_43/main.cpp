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
		for (int i = 1;i <= n;++i) {
			for (int j = n;j >= i;--j) {
				if (i + j == m) {
				  /*int min = i < j ? i : j;
					int max = i > j ? i : j;*/
					cout << i <<" "<<j << endl;
				}
			}
		}
		if (n >= m) {
			cout << m << endl;
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

#if 1
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