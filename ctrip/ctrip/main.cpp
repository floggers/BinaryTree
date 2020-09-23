#include <iostream>
#include <vector>
#include <string>
using namespace std;

int howManycps(string str) {
	vector<int> cha(26, 0);
	int num = 0;
	for (int i = 0;i < str.size();++i) {
		for (int j = i + 1;j < str.size();++j) {
			if (str[i] + str[j] == 'a' + 'z' && !cha[str[i] - 'a'] && !cha[str[j] - 'a']) {
				cha[str[i] - 'a'] = 1;
				cha[str[j] - 'a'] = 1;
				++num;
			}
		}
	}
	return num;
}

int main() {
	string s1;
		while (getline(cin, s1)) {
			cout << howManycps(s1) << endl;
		}
	return 0;
}