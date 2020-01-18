#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string toLowerCase(string &str) {
		for (auto &i : str) {
			if (i>='A'&&i<='Z'){
				i = i + 32;
			}
		}
		return str;
	}

	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		reverse(nums.begin(),nums.end());
		reverse(nums.begin(), nums.end()-k%len-1);
		reverse(nums.end() - k%len-1, nums.end());
	}
};


int main() {
	string str1("ASsadf");
	int arr[] = { 1,2,3,4,5,6,7 };
	vector<int> ivec1(arr,arr+sizeof(arr)/sizeof(arr[0]));
	Solution A;
	A.toLowerCase(str1);
	A.rotate(ivec1,3);
	cout << str1<<endl;
	for (auto i : ivec1) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}