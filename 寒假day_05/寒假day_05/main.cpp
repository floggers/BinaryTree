#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size() - 1;i++) {
			if (nums[i] == nums[i + 1]) {
				return 1;
			}
		}
		return 0;
	}

	bool containsDuplicate2(vector<int>& nums) {
		unordered_map<int, int>count;
		for (auto &e : nums) {
			count[e]++;
		}
		/*for (auto &e : count) {
			if (e.second > 1) {
				return 1;
			}
		}
		return 0;*/
		return count.size() != nums.size();
	}

	bool isLongPressedName(string name, string typed) {
		string::iterator strit1 = name.begin();
		string::iterator strit2 = typed.begin();
		while (strit1 < name.end() && strit2<typed.end()) {
			if (*strit1 == *strit2) {
				strit1++;
			}
			strit2++;
		}
	/*	if (*strit1) {
			return 0;
		}
		return 1;*/
		return strit1 == name.end();
	}
};

int main() {
	int arr[5] = { 0,4,4,1,3 };
	vector<int>test(arr, arr + 5);
	string name("kikcxmvzi");
	string typed("kiikcxxmmvvzz");
	Solution A;
	//cout<<A.containsDuplicate(test);
	cout << A.isLongPressedName(name, typed);
	system("pause");
	return 0;
}