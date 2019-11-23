#include <iostream>
using namespace std;

#if 1

int Max_continuous_num(int num) {
	int sum = 0;
	int n = 0;
	int buf;
	int arr[32];
	while (num > 0) {
		buf = num % 2;
		arr[n] = buf;
		n++;
		num = num / 2;
	}
	for (int i = 0;i < n;i++) {
		sum += arr[i];
	}
	return sum;
}


int main() {
	int num;
	while (cin >> num) {
		cout << Max_continuous_num(num)<<endl;
	}
	system("pause");
	return 0;
}

#endif