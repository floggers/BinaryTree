#include <iostream>
#include <string>
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



int main() {

	system("pause");
	return 0;
}

#endif