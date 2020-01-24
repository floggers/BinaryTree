#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	vector<int> sortArrayByParity(vector<int>& A) {
		int left = 0;
		int right = A.size() - 1;
		while (left < right) {
			if (A[left] % 2 != 0) {
				if (A[right] % 2 == 0) {
					int tmp = 0;
					tmp = A[left];
					A[left] = A[right];
					A[right] = tmp;
					left++;
					right--;
				}
				else {
					right--;
				}
			}
			else {
				left++;
			}
		}
		return A;
	}

	int pivotIndex(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int tmp1 = nums[left];
		int tmp2 = nums[right];
		while (left + 1 < right) {
			if (tmp1 < tmp2) {
				tmp1 += nums[left + 1];
				left++;
			}
			else if (tmp1 > tmp2) {
				tmp2 += nums[right - 1];
				right--;
			}
			else if (left + 1 == right - 1 && tmp1 == tmp2) {  
					return left + 1;
			}
			else {
				tmp1 += nums[left + 1];
				tmp2 += nums[right - 1];
				left++;
				right--;
			}
		}
		return -1;
	}

};

int main() {
	int arr[] = { 1,2,3,4,5,10 };
	vector<int>test(arr, arr + 6);
	Solution A;
	/*A.sortArrayByParity(test);
	for (auto i : test) {
		cout << i << " ";
	}*/
	cout << A.pivotIndex(test);
	system("pause");
	return 0;
}