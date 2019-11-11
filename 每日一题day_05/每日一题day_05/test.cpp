#include <iostream>
#include <string>
using namespace std;

#if 1

int Function(string &s1, string &s2) {
	int num2 = s2.size();
	int num = s1.size() +1;
	int func_num = 0;
	string::iterator it1 = s1.begin();
	string::iterator it2 = s1.end();
	for (int i = 0;i < num;i++) {
		int count = 0;
		s1.insert(i, s2);
		it1 = s1.begin();
		it2 = s1.end();
		while (it1 < it2-1) {
			if (*it1 == *(it2-1)) {
				it1++;
				it2--;
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == s1.size() / 2) {
			func_num++;
		}
		s1.erase(i,num2);
		it1 = s1.begin();
		it2 = s1.end();
	}
	return func_num;
}

int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin,s2);
	cout << Function(s1, s2);
	system("pause");
	return 0;
}

#endif