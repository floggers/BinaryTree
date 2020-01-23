#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<int> sortedSquares(vector<int>& A) {
		int N = A.size();
		vector<int>buf(N, 0);
		for (int i = 0;i < N;i++) {
			buf[i] = A[i] * A[i];
		}
		sort(buf.begin(),buf.end());
		return buf;
	}

	string reverseOnlyLetters(string S) {
		int start = 0;
		int end = S.size() - 1;
		char buf;
		while (start < end) {
			if (!(S[start] >= 'A'&&S[start] <= 'z')) {
				start++;
			}
			else if (!(S[end] >= 'A'&&S[end] <= 'z')) {
				end--;
			}
			else {
				buf = S[start];
				S[start] = S[end];
				S[end] = buf;
				start++;
				end--;
			}
		}
		return S;
	}

};

int main() {
	int arr[] = { -4,-3,-1,0,2,6 };
	vector<int>array(arr, arr + 6);
	string str("A-bcdE&f");
	Solution A;
	/*for (auto i : A.sortedSquares(array)) {
		cout << i << " ";
	}*/
	cout << A.reverseOnlyLetters(str);
	system("pause");
	return 0;
}