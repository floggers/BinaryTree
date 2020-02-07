#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int flag = 1;
		int ret = 0;
		while (str[i] == ' ') {
			i++;
		}
		if (i == str.size()) {
			return 0;
		}
		else if (str[i] == '-') {
			flag = 0;
		}
		else if (isdigit(str[i])) {
			ret = str[i] - '0';
		}
		else if (str[i] != '+') {
			return 0;
		}
		while (++i < str.size() && isdigit(str[i])) {
			int r = str[i] - '0';
			if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && r > 7)) {
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			ret = ret * 10 + r;
		}
		return flag > 0 ? ret : -ret;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>buf(2, -1);
		int left = 0;
		int right = nums.size() - 1;
		if (nums.size() == 1 && target==nums[0]) {
			buf[0] = 0;
			buf[1] = 0;
		}
		while (left < right ) {
			if (nums[left] < target) {
				left++;
			}
			 if (nums[left] == target) {
				buf[0] = left;
			}
		    if (nums[right] > target) {
				right--;
			}
			 if (nums[right] == target) {
				buf[1] = right;
			}
			 if (nums[left] == nums[right]) {
				 break;
			 }
		}
		return buf;
	}

};

int main() {
	string a("    -987234Yttt456");
	int arr[1] = { 1};
	vector<int> v1(arr, arr + 1);
	Solution A;
	//cout << A.myAtoi(a);
	for (auto i : A.searchRange(v1, 1)) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}