#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1;
			++count;
		}
		return count;
	}

	double Power(double base, int exponent) {
		double res = 1;
		int flag = 1;
		if (exponent < 0) {
			flag = 0;
			exponent = -exponent;
		}
		while (exponent){
			res *= base;
			--exponent;
		}
		return flag > 0 ? res : 1 / res;
	}

	void reOrderArray(vector<int> &array) {
		int len = array.size();
		for (int i = 0;i < len;++i) {
			if (array[i] % 2 == 0) {
				array.push_back(array[i]);
				array.erase(array.begin() + i);
				--i;
				--len;
			}
		}
	}
};

int main() {
	Solution A;
	vector<int> vtest{ 12,2,4,6,10 };
	//cout << A.NumberOf1(10) << endl;
	A.reOrderArray(vtest);
	for (auto &i : vtest) {
		cout << i << "  ";
	}
	system("pause");
	return 0;
}