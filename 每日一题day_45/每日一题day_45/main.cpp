#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 0

int main() {
	string str1, str2;
	while (cin >> str1) {
		cin >> str2;
		for (int i = 0;i < str2.size();++i) {
			int pos = str1.find(str2[i]);
			if (pos == -1) {
				cout << "No" << endl;
				break;
			}
			else {
				str1.erase(pos, 1);		
			}
			if (i == str2.size() - 1) {
				cout << "Yes" << endl;
			}
		}
	}
	system("pause");
	return 0;
}

#endif

#if 1

int main() {
	int n;
	while (cin >> n) {
		vector<string> res;
		for (int i = 0;i < n;++i) {
			string buf;
			cin >> buf;
			res.push_back(buf);
		}
		string brother;
		cin >> brother;
		int k;
		cin >> k;
		sort(res.begin(), res.end());
		int count = 0;
		int tmp = 0;
		for (int i = 0;i < res.size();++i) {
			if (res[i] == brother) {
				continue;
			}
			else if (res[i].size() != brother.size()) {
				continue;
			}
			else {
				bool flag = true;
				for (int j = 0;j < res[i].size();++j) {
					if (res[i].find(brother[j]) == -1) {
						flag = false;
					}
					else {
						int pos = res[i].find(brother[j]);
						res[i][pos] = '0';
					}
				}
				if (flag) {
					count++;
					if (count == k) {
						tmp = i;
					}
				}
			}
		}
		cout << count << endl;
		cout << res[tmp] << endl;
	}
	system("pause");
	return 0;
}

#endif