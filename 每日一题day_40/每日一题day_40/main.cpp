#include <iostream>
using namespace std;

class Solution {
public:

	long long no_Receive(int n) {
		long long sum = 1.0;
		for (int i = n;i >= 2;--i) {
			sum *= i;
		}
		long long arr[21] = { 0 };
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 1;
		for (int i = 3;i < 21;++i) {
			arr[i] = (i - 1)*(arr[i - 2] + arr[i - 1]);
		}
		return arr[n];
	}



};

int main() {
	Solution A;
	int n;
	while (cin >> n) {
		cout << A.no_Receive(n) << endl;
	}

	system("pause");
	return 0;
}