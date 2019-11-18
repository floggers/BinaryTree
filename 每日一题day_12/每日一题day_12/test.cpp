#include <iostream>
using namespace std;

#if 0

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m = m << j;
		return n | m;
	}
};

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	BinInsert A;
	cout<<A.binInsert(a, b, c, d)<<endl;
	system("pause");
	return 0;
}

#endif

#if 1

bool isprime(int num) {
	if (num == 0) {
		return false;
	}
	if (num == 1) {
		return true;
	}
	for (int i = 2;i < num;i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int num;
	while (cin >> num) {
		int left = num / 2;
		int right = num / 2;
		while (left >= 1 || right < num) {
			if ((isprime(left)) && (isprime(right))) {
				cout << left << endl << right << endl;
				break;
			}
			else {
				right++;
				left--;
			}
		}
	}
	system("pause");
	return 0;
}

#endif