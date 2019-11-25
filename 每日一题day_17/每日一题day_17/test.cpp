#include <iostream>
using namespace std;

#if 1

int getTotalcount(int month) {
	if (month == 1||month == 2) {
		return 1;
	}
	if (month >= 3) {
		return getTotalcount(month-1) + getTotalcount(month - 2);
	}
}

int main() {
	int month;
	cin >> month;
	cout << getTotalcount(month) << endl;
	system("pause");
	return 0;
}

#endif