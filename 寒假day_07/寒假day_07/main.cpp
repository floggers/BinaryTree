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

};

int main() {
	int arr[] = { 1,3,2,4 };
	vector<int>test(arr, arr + 4);
	Solution A;
	A.sortArrayByParity(test);
	for (auto i : test) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}