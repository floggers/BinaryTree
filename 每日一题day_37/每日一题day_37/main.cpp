#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	while (cin >> n) {
		set<string> list;
		vector<string> res;
		for (int i = 0;i < n;++i) {
			cin >> str;
			list.insert(str);
		}
		auto it = list.begin();
		string cur, next;
		cur = *it;
		for (++it;it != list.end();++it) {
			auto tmp = it;
			next = *it;
			if (cur == next) {
				cur = next;
			}
			else if (cur.size() < next.size() && cur == next.substr(0, cur.size()) && next[cur.size()] == '/') {
				cur = next;
			}
			else {
				res.push_back(cur);
				cur = next;
			}
		}
		auto lst = list.end();
		res.push_back(*(--lst));
		int len = res.size();
		for (int i = 0;i < len;++i) {
			cout << "mkdir -p " << res[i] << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}