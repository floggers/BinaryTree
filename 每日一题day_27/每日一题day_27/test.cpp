#include <iostream>
using namespace std;

#if 1

class Solution {
public:
	int sum = 0;
	int tmp = 0;
	int Add(int num1, int num2) {
		if (num2 == 0) {
			return num1;
		}
		else {
			//��һ������Ӳ���λ  
			sum = num1 ^ num2;
			//�ڶ�������ý�λ��ֵ  
			tmp = (num1 & num2) << 1;
			//��������sum��tmp���  
			return Add(sum, tmp);
		}
	}
};




int main() {
	Solution A;
	int a, b;
	while (cin >> a >> b) {
		cout << A.Add(a, b) << endl;
	}
	system("pause");
	return 0;
}

#endif

#if 0

int main() {
	double a, b, c;
	while (cin >> a >> b >> c) {
		if (a + b > c&&a + c > b&&b + c > a) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}

#endif