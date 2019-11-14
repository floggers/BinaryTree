#include <iostream>
using namespace std;

#if 1

int Func(int a, int b) {
	int outc = 0;
	int min, max,temp;
	min = a > b ? b : a;
	max = a > b ? a : b;
	while (max - min != 0) {
		temp = max - min;
		max = temp > min ? temp : min;
		min = temp > min ? min : temp;
	}
	outc = a*b / max;
	return outc;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << Func(a, b);
	system("pause");
	return 0;
}

#endif