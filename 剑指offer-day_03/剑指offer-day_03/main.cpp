#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) {
			return 0;
		}
		vector<int> buf(rotateArray);
		for (auto & i : rotateArray) {
			buf.push_back(i);
		}
		for (int i = 0;i < buf.size();i++) {
			if (buf[i + 1] < buf[i] && i + 1 < buf.size()) {
				return buf[i + 1];
			}
		}
		return rotateArray[0];
	}

	int Fibonacci1(int n) {                                    //未曾经过优化
		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			return 1;
		}
		else {
			return Fibonacci1(n - 2) + Fibonacci1(n - 1);
		}
	}

	int Fibonacci2(int n) {
		int *buf = new int[n];
		buf[0] = 0;
		buf[1] = 1;
		for (int i = 2;i <=n;i++) {
			buf[i] = buf[i - 1] + buf[i - 2];
		}
		delete[] buf;
		return buf[n];
	}

};

int main() {

	system("pause");
	return 0;
}