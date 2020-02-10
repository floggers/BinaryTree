#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> buf;
		buf.push_back({});
		for (auto v : nums) {
			int len = buf.size();
			for (int i = 0;i < len ;i++) {
				auto tmp = buf[i];
				tmp.push_back(v);
				buf.push_back(tmp);
			}
		}
		return buf;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
	// can not
	}

};

int main() {
	int arr[] = { 1,2,3,4 };
	vector<int> test(arr, arr + 4);
	Solution A;
	for (auto i : A.subsets(test)) {
		for (int j = 0;j < i.size();j++) {
			cout << i[j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}