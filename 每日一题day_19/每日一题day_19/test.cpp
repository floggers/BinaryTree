#include <iostream>
#include <string>
using namespace std;

#if 0

int main() {
	string str1,str2;
	string buf1,buf2;
	int n = 0;
	getline(cin, str1);
	getline(cin, str2);
	//string::iterator sib1 = str1.begin();
	//string::iterator sib2 = str2.begin();
	const char *ps1 = str1.c_str();
	const char *ps2 = str2.c_str();
	const char *ps2b = str2.c_str();
	while (ps1) {
		if (*ps1 == *ps2) {
			buf1 += *ps1;
		}
		ps1++;
	}
	system("pause");
	return 0;
}

#endif


#if 1

int max_bottle(int n) {
	int num = 0;
	int num1 = 0;
	while (n) {
		if (n == 1 || n == 0) {
			return num;
		}
		 if (n == 2) {
			num += 1;
			return num;
		}
		else {
			num += n / 3;
		}
		n = n % 3 + num-num1;
		num1 = num;
	}
	return num;
}

int main() {
	int n;
	while (cin >> n) {
		if(n==0){
			break;
		}
		cout << max_bottle(n) << endl;
	}
	system("pause");
	return 0;
}

#endif