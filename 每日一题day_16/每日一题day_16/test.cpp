#include <iostream>
#include <string>
using namespace std;

#if 0

int count(int num) {
	int count = 0;
	int sum = 0;
	for (int i = 1;i <= num;i++) {
		for (int j = 1;j < i;j++) {
			if (i%j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			count++;
		}
		sum = 0;
	}
	return count;
}

int main() {
	int num;
	cin >> num;
	cout << count(num)<<endl;
	system("pause");
	return 0;
}

#endif

#if 1



int main() {

	system("pause");
	return 0;
}

#endif