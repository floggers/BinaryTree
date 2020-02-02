#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>buf;
		buf.resize(2);
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
		
	}
};

int main() {
	int arr[5] = { 1,7,3,4,5 };
	vector<int>test(arr, arr + 5);
	Solution A;
	for (auto i : A.twoSum(test,10)) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}