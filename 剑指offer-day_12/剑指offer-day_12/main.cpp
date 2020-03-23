#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int len = array.size();
		if (!len) {
			return 0;
		}
		int sum = array[0];
		int sum_max = array[0];
		for (int i = 1;i < len;++i) {
			if (sum < 0) {
				sum = array[i];
			}
			else{
				sum += array[i];
			}
			sum_max = sum > sum_max ? sum : sum_max;
		}
		return sum_max;
	}

	int NumberOf1Between1AndN_Solution(int n){
		if (n == 0) {
			return 0;
		}
		int sum = 0;
		while (n) {
			int right = n % 10;
			int left = n / 10;
			if (right>=1) {
				sum += left;
			}
			if (left>1) {
				sum += 10;
			}
			else if (left == 1) {
				sum += (right + 1);
			}
			else {
				sum += right > 0 ? 1 : 0;
			}
			n = n / 10;
		}
		return sum;
	}

	int NumberOf1Between1AndN_Solution2(int n) {
		int count = 0;
		for (int i = 1;i <= n;++i) {
			count += num_1ofNumbs(i);
		}
		return count;
	}

	int num_1ofNumbs(int n) {
		string str = to_string(n);
		int len = str.size();
		int count = 0;
		for (int i = 0;i < len;++i) {
			if (str[i] == '1') {
				++count;
			}
		}
		return count;
	}
};


int main() {
	vector<int> v = { 6,-3,-2,7,-15,1,2,2 };
	Solution A;
	//cout << A.FindGreatestSumOfSubArray(v);
	cout << A.NumberOf1Between1AndN_Solution2(10000);
	system("pause");
	return 0;
}