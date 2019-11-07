#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#if 0
void reverse_str(char* begin,char* end) {
	while (begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
	
}

void reverse_word(char* src) {
	char* begin = src;
	char* end = src;
	while (*src) {
		if (*src != ' ') {
			 begin = src;
			while (*src != ' '&&*src) {
				src++;
			}
			src = src - 1;
			end = src ;
			reverse_str(begin, end);
		}
		src++;
	}
}

int main() {
	char str[100] = { 0 };
	int i = 0;
	while (1) {
		str[i]= getchar();
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
		i++;
	}
	reverse_str(str, str + strlen(str) - 1);
	reverse_word(str);
	cout << str << endl;
	system("pause");
	return 0;
}
#endif

#if 1

int count(vector<int> &v) {
	int ret = 0;

	return ret;
}
int main() {
	int n;       
	vector<int> v;
	cin >> n;         //n个正整数
	v.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	cout << count(v);
	system("pause");
	return 0;
}

#endif