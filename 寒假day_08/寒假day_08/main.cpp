#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	////Êý¾ÝÒç³ö
	//vector<int> plusOne(vector<int>& digits) {
	//	int buf = 0;
	//	int sum = 0;
	//	vector<int>buffer;
	//	for (int i = 0;i <= digits.size() - 1;i++) {
	//		buf = buf * 10 + digits[i];
	//	}
	//	sum = buf + 1;
	//	while (sum) {
	//		buffer.push_back(sum % 10);
	//		sum /= 10;
	//	}
	//	int n = buffer.size();
	//	digits.resize(n);
	//	for (int i = 0;i < n;i++) {
	//		digits[i] = buffer[n - i - 1];
	//	}
	//	return digits;
	//}

	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1;i >= 0;i--) {
			digits[i]++;
			digits[i] = digits[i] % 10;
			if (digits[i] != 0) {
				return digits;
			}
		}
		digits.resize(digits.size() + 1, 0);
		digits[0] = 1;
		return digits;
	}

	int thirdMax(vector<int>& nums) {
		set<int>hash_set(nums.begin(), nums.end());
		while(hash_set.size() > 3) {
			hash_set.erase(*hash_set.begin());
		}
		if (hash_set.size() < 3) {
			return *hash_set.rbegin();
		}
		else {
			return *hash_set.begin();
		}
	}

};

int main() {
	int arr[5] = { 1,9,5,7,4 };
	vector<int>test(arr, arr + 5);
	Solution A;
	//A.plusOne(test);
	/*for (auto i : test) {
		cout << i << " ";
	}*/
	cout << A.thirdMax(test);
	system("pause");
	return 0;
}