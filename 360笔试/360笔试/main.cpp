#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#if 1

string help(string str1, string str2, char f) {
	string res;
	if (f == '+') {
		if (str1[2] == str2[2]) {
			int tmp = str1[0] - '0' + str2[0] - '0';
			string up = to_string(tmp);
			string down = to_string(str2[2] - '0');
			res += up;
			res += "/";
			res += down;
		}
		if (str1[2] != str2[2]) {
			int tmp1 = (str1[0] - '0')*(str2[2] - '0') + (str2[0] - '0')*(str1[2] - '0');
			int tmp2 = (str1[2] - '0')*(str2[2] - '0');
			string up = to_string(tmp1);
			string down = to_string(tmp2);
			res += up;
			res += "/";
			res += down;
		}
	}
	else if (f == '-') {
		if (str1[2] == str2[2]) {
			int tmp = str1[0] - '0' - str2[0] - '0';
			string up = to_string(tmp);
			res += up;
			res += "/";
			res += str2[2];
		}
		if (str1[2] != str2[2]) {
			int tmp1 = (str1[0] - '0')*(str2[2]-'0') - (str2[0] - '0')*(str1[2]-'0');
			int tmp2 = (str1[2] - '0')*(str2[2] - '0');
			string up = to_string(tmp1);
			string down = to_string(tmp2);
			res += up;
			res += "/";
			res += down;
		}
	}
	else if (f == '*') {
		int tmp = (str1[0] - '0') * (str2[0] - '0');
		string up = to_string(tmp);
		res += up;
		res += "/";
		res += to_string((str1[2] - '0')*(str2[2] - '0'));
	}
	else {
		int tmp = (str1[0] - '0') * (str2[2] - '0');
		string up = to_string(tmp);
		res += up;
		res += "/";
		res += to_string((str1[2] - '0')*(str2[0] - '0'));
	}
	return res;
}

int maxnum(int num1, int num2) {
	while (num2%num1) {
		int tmp = num2%num1;
		num2 = num1;
		num1 = tmp;
	}
	return num1;
}

string solution(string str) {
	string tmp = str;
	string str1 = str.substr(0, 3);
	string str2 = tmp.substr(6);
	string res = help(str1, str2, str[4]);
	if (res[0] != '-') {
		int up = res[0] - '0';
		int down = 0;
		if (res[3] == ' ') {
			 down = res[2] - '0';
		}
		else {
			down=10*(res[2]-'0')+res[3]-'0';
		}
		int max = down > up ? down : up;
		int min = down > up ? up : down;
		int _maxnum = maxnum(min, max);
		up = up / _maxnum;
		down = down / _maxnum;
		res = to_string(up) + '/' + to_string(down);
	}
	else {
		int up = res[1] - '0';
		int down = res[3] - '0';
		int max = down > up ? down : up;
		int min = down > up ? up : down;
		int _maxnum = maxnum(min, max);
		up = up / _maxnum;
		down = down / _maxnum;
		res = "-" + to_string(up) + '/' + to_string(down);
	}
	return res;
}

int main() {
	string str;
	while (getline(cin,str)) {
		string res = solution(str);
		cout << res << endl;
	}
	system("pause");
	return 0;
}

#endif


#if 0

int main() {
	int n;
	while (cin >> n) {
		int *a = new int[n+1];
		cin >> a[0];
		int res = 0;
		int count = 0;
		for (int i = 1;i <= n;++i) {
			for (int j = 0;j <= a[i-1];++j) {
				a[i] = a[i - 1] - j;
				if (a[i] == 0) {
					++res;
				}
				++count;
			}
		}
		printf("%.5f\n", res / count);
	}
	system("pause");
	return 0;
}

#endif



#if 0
int main() {
	int n, m;
	while (cin >> n) {   //人数
		cin >> m;    //连赢场数
		if (n == 0 || m == 0) {
			return 0;
		}
		queue<int> qu1;
		queue<int> qu2;
		for (int i = 0;i < n;++i) {
			int num;
			cin >> num;
			qu1.push(num);
		}
		int win = 0;
		int count = 0;
		qu2.push(qu1.front());
		qu1.pop();
		while (!qu1.empty()) {
			if (qu2.front() < qu1.front()) {
				qu2.push(qu1.front());
				qu1.pop();
				int min = qu2.front();
				qu2.pop();
				qu1.push(min);
				win = 0;
				++win;
				++count;
			}
			else  if (qu2.front() > qu1.front()) {
				int min = qu1.front();
				qu1.pop();
				qu1.push(min);
				++win;
				++count;
				if (win == m) {
					break;
				}
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}

#endif

