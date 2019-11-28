#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0

void reverse_str( char* begin, char* end) {
	while (begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

int main() {
	char str1[100] = { 0 };
	int i = 0;
	while (1) {
		str1[i] = getchar();
		if (str1[i] == '\n') {
			str1[i] = '\0';
			break;
		}
		i++;
	}
	reverse_str(str1,str1+strlen(str1)-1);
	cout << str1 << endl;
	system("pause");
	return 0;
}

#endif

#if 0

string reverse_str(string s) {
	string buf;
	for (int i = s.size() - 1;i >= 0;i--) {
		buf.push_back(s[i]);
	}
	s = buf;
	return s;
}

int main() {
	string str;
	getline(cin, str);
	str=reverse_str(str);
	cout << str << endl;
	system("pause");
	return 0;
}

#endif

#if 0

int main() {
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	while (i-- > 0) {
		cout << s[i];
	}
	cout << endl;
	system("pause");
	return 0;
}

#endif

#if 1

int maxLong_Child_str(string str1, string str2) {
	vector<vector<int>> table(str1.size(), vector<int>(str2.size(),0));
	int maxLen = 0;
	//int maxEnd = 0;
	for (int i = 0;i < str1.size() ;i++) {
		for (int j = 0;j < str2.size() ;j++) {
			if (str1[i] == str2[j]) {
				if (i == 0 || j == 0) {
					table[i][j] = 1;
				}
				else {
					table[i][j] = table[i - 1][j - 1] + 1;
				}
			}
			if (table[i][j] > maxLen) {
				maxLen = table[i][j];
				//maxEnd = i;              //若记录i,则最后获取的是str1的子串
			}
		}
	}
	//return str1.substr(maxEnd - maxLen + 1, maxLen);    //substr(起始位置,切割长度)
	return maxLen;
}

int main() {
	string str1, str2;
	int buf;
	cin >> str1 >> str2;
	buf = maxLong_Child_str(str1, str2);
	cout << buf << endl;
	system("pause");
	return 0;
}

#endif