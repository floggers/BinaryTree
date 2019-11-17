#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		for (int i = 0; i < 3; i++){
		int sum_row = 0;
		int sum_cow = 0;
		for (int j = 0; j < 3; j++){
			sum_row += board[i][j];
			sum_cow += board[j][i];
		}
		if (sum_row == 3){
			return true;
		}
		if (sum_cow == 3){
			return true;
		}
	}
	int first = 0;
	int second = 0;
	for (int i = 0; i < 3; i++) {
		first += board[i][i];
		second += board[i][3 - 1 - i];
	}
	if (first == 3) {
		return true;
	}
	if (second == 3) {
		return true;
	}
	return false;
}
};

int main() {
	vector<vector<int>> v{ {0,0,1},{-1,1,-1},{0,-1,1} };
	Board A;
	cout<<A.checkWon(v);
	system("pause");
	return 0;
}

#endif

#if 1

int numNumber(string str, int k){
	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
	int num = 0;
	for (int i = 0; i < k; i++) {
		//这里需要注意的是，因为传进来的是字符char，所以要减去 ‘0’变为 int 数字
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			num++;
		}
	}
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else { return 20; }
}

int numChar(string str, int k){
	//根据ASCII码判断字母大小写
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			small++;
		}
	}
	if ((small + big) == 0) {
		return 0;
	}
	else if (small == k || big == k) {
		return 10;
	}
	else if (small > 0 && big > 0) {
		return 20;
	}

	return 0;
}

int numSymbal(string str, int k){
	int num = 0;
	for (int i = 0; i < k; i++) {
		//除去字母，数字，其它都为符号
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else { return 25; }
}


int main() {
	string str;
	while (cin >> str) {
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4) {
			sum1 = 5;
		}
		else if (k >= 8) {
			sum1 = 25;
		}
		else { sum1 = 10; }
		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0)) {
			if (sum2 == 10) {
				sum5 = 3;
			}
			else {
				sum5 = 5;
			}
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0) {
			sum5 = 2;
		}
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	system("pause");
	return 0;
}

#endif