#include "bigint.h"

string BigInt::Add(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int dif = len1 - len2;
	if (dif < 0) {
		dif = len2 - len1;
		num1.insert(0, dif, '0');
	}
	else {
		num2.insert(0, dif, '0');
	}
	int step = 0;  //进位
	for (int i = num1.size() - 1;i >= 0;--i) {
		num1[i] = (num1[i] - '0') + (num2[i] - '0') + step;
		if (num1[i] > 9) {
			num1[i] = num1[i] - 10 + '0';
			step = 1;
		}
		else {
			num1[i] = num1[i] + '0';
			step = 0;
		}
	}
	if (step) {
		num1.insert(0, "1");
	}
	return num1;
}

string BigInt::Sub(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int dif = len1 - len2;
	if (dif < 0) {
		dif = len2 - len1;
		num1.insert(0, dif, '0');
	}
	else {
		num2.insert(0, dif, '0');
	}
	for (int i = num1.size() - 1;i >= 1;--i) {
		num1[i] = (num1[i] - '0') - (num2[i] - '0');
		if (num1[i] >= 0) {
			num1[i] += '0';
		}
		else {
			num1[i] = num1[i] + 10 + '0';
			num1[i - 1] -= 1;
		}
	}
	if (num1[0] == num2[0]) {
		num1.erase(0, 1);         //删除从位置0开始的1个元素
	}
	else {
		num1[0] = (num1[0] - '0') - (num2[0] - '0') + '0';
	}
	while (num1[0] != '0') {
		num1.erase(0, 1);
	}
	return num1;
}


string Mul(string num1, string num2);
pair<string, string> Dev(string num1, string num2);