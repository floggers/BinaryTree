#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int j = 0;
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] != val) {
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}

	int searchInsert(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] == target) {
				return i;
			}
			else if (target > nums[i] && target < nums[i + 1] && i + 1 < nums.size()) {
				return i + 1;
			}
			else if (target < nums[0]) {
				return 0;
			}
			else if(target>nums[nums.size()-1]){
				return nums.size();
			}
		}
	}
};

int main() {
	Solution A;
	vector<int> vi1;
	vi1.push_back(1);
	vi1.push_back(0);
	vi1.push_back(3);
	vi1.push_back(5);
	vi1.push_back(2);
	vi1.push_back(4);
	vi1.push_back(9);
	cout<<A.searchInsert(vi1, 10);
	system("pause");
	return 0;
}