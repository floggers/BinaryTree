#include <iostream>
#include <string>
using namespace std;

void reverse(string &src,int begin,int end) {
	while (begin < end) {
		char tmp;
		tmp = src[begin];
		src[begin] = src[end];
		src[end] = tmp;
		begin++;
		end--;
	}
}

int main() {
	string s("123456");
	reverse(s, 0, 5);
	reverse(s, 0, 1);
	reverse(s, 2, 5);
	cout << s;
	system("pause");
	return 0;
}