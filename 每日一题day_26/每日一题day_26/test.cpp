#include <iostream>
using namespace std;

#if 1

class Solution {
public:
	int jumpFloorII(int number) {
		return  1 << --number;
	}
};
		/*	f(1) = 1;
			f(2) = f(1) + 1 = f(1) + f(1) = 2 * f(1) = 2;
			f(3) = f(2) + f(1) + 1 = f(2) + f(1) + f(1)
			= f(2) + 2 * f(1) = f(2) + f(2) = 2 * f(2) = 2 * 2;
			f(k) = f(k - 1) + f(k - 2) + бн + f(2) + f(1) + 1
			= f(k - 1) + f(k - 2) + бн + f(3) + f(2) + f(1) + f(1)
			= f(k - 1) + f(k - 2) + бн + f(3) + f(2) + f(2гй
				= f(k - 1) + f(k - 2) + f(k - 3) + бн + f(3) + f(3)
				= 2 * f(k - 1)
				= 2 . ^ (k - 1);      */

int main() {
	Solution A;
	int n;
	cin >> n;
	cout << A.jumpFloorII(n) << endl;
	system("pause");
	return 0;
}

#endif