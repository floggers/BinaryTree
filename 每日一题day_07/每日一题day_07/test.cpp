#include <iostream>
#include <string>
using namespace std;

#if 0
int Fib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}


int Min_step_To_Fib(int num) {
	int n = 0;
	int left = 0;
	int right = 0;
	while (1) {
		if (Fib(n) < num) {
			 left = num - Fib(n);
		}
		else {
			 right = Fib(n) - num;
			break;
		}
		n++;
	}
	if (left < right) {
		return left;
	}
	return right;
}

int main() {
	int n;
	cin >> n;
	cout << Min_step_To_Fib(n);
	system("pause");
	return 0;
}
#endif

#if 1

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		int left = 0;
		int right = 0;
		if (n%2) {
			return false;
		}
		for (int i = 0;i < n;i++) {
			if ((A[i] != '(' )&&( A[i] != ')')) {
				return false;
			}
			if (A[i] == '(') {
				left++;
			}
			if (A[i] == ')') {
				right++;
			}
			if (right > left) {
				return false;
			}
		}
		if (left == right) {
			return true;
		}
		return false;
	}
};

int main() {
	int n;
	Parenthesis A;
	string s;
	getline(cin, s);
	cin >> n;
	cout<<A.chkParenthesis(s,n);
	system("pause");
	return 0;
}

#endif