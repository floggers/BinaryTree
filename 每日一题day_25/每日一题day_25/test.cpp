#include <iostream>
#include <vector>
using namespace std;

#if 1

int Fib(int n) {
	 if (n == 0) {
		return 0;
	}
	 else if (n == 1) {
		return 1;
	}
	 else if (n == 2) {
		 return 2;
	 }
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main() {
	int n;
	cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
			printf("%04d", Fib(v[i]) % 10000);
		}
		cout << endl;
	system("pause");
	return 0;
}

#endif