#include <iostream>
#include <math.h>
using namespace std;

#if 1

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		cout << total << " " << left << endl;
	}
	system("pause");
	return 0;
}

#endif