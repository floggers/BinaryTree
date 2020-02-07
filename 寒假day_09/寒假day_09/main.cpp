#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>buf;
		buf.resize(2);
		for (int i = 0;i < nums.size();i++) {
			for (int j = 1 + i;j < nums.size();j++) {
				int dif = target - nums[i];
				if (dif == nums[j]) {
					buf[0] = i;
					buf[1] = j;
				}
			}
		}
		return buf;
	}

	string addBinary(string a, string b) {
		int a1 = a.size();
		int b1 = b.size();
		while (a1 < b1) {
			a = '0' + a;
			a1++;
		}
		while (a1 > b1) {
			b = '0' + b;
			b1++;
		}
		for (int i = a1-1;i > 0;i--) {
			a[i] = a[i] + b[i] - '0';
			if (a[i] >= '2') {
				a[i] = (a[i] - '0') % 2 + '0';
				a[i - 1] = a[i - 1] + 1;
			}
		}
		a[0] = a[0] + b[0] - '0';
		if (a[0] >= '2') {
			a[0] = (a[0] - '0') % 2 + '0';
			a = '1' + a;
		}
		return a;
	}

};

int main() {
	int arr[5] = { 1,7,3,4,5 };
	string a("1111");
	string b("1110");
	string c;
	vector<int>test(arr, arr + 5);
	Solution A;
	for (auto i : A.twoSum(test,11)) {
		cout << i << " ";
	}
	cout << endl;
	cout << A.addBinary(a, b) << endl;
	c =  c+'f';
	cout << c;
	system("pause");
	return 0;
}