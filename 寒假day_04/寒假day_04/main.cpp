#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		if (!(s.size())) {
			return 0;
		}
		for (int i = 0;i < s.size();i++) {
			if (s[i] != ' ') {
				count++;
			}
			else if(s[i+1] && i+1<s.size() && s[i+1]!=' '){
				count = 0;
			}
		}
		return count;
	}

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.resize(m + n);
		for (int i = m, j = 0;i < m + n, j < n;i++, j++) {
			nums1[i] = nums2[j];
		}
		sort(nums1.begin(), nums1.end());
	}

};

int main() {
	Solution A;
	//cout<<A.lengthOfLastWord("b   a    ");
	vector<int>nums1(3, 0);
	vector<int>nums2(2, 1);
	A.merge(nums1, 3, nums2, 2);
	for (auto i : nums1) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}