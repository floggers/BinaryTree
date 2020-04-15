#include <iostream>
#include <string>
#include <stack>
using namespace std;

#if 0

int main() {
	string str;
	while (cin >> str) {
		string res;
		for (int i = 0;i < str.size();++i) {
			if (str[i] == '_') {
				char buf = str[i + 1] - 32;
				res.push_back(buf);
				++i;
			}
			else {
				res.push_back(str[i]);
			}
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}

#endif

#if 1

int main() {
	string str;
	while (getline(cin , str)) {
		stack<string> res;
		string buf;
		for (int i = 0;i < str.size();++i) {
			if (!(str[i] >= 'a'&&str[i] <= 'z')) {
				if (!(str[i] >= 'A'&&str[i] <= 'Z')) {
					if (!buf.empty()) {
						res.push(buf);
						buf.clear();
					}
				}
			}
			if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')) {
				buf.push_back(str[i]);
				if (i == str.size() - 1) {
					res.push(buf);
				}
			}
		}
		int len = res.size();
		for (int i = 0;i < len;++i) {
			if (i < len - 1) {
				cout << res.top() << " ";
				res.pop();
			}
			else {
				cout << res.top() << endl;
				res.pop();
			}
		}
	}
	system("pause");
	return 0;
}

#endif