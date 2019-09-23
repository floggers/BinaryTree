#include <iostream>
#include <vector>
using namespace std;
	int FindGreatestSumOfSubArray(vector<int> & array) {
		if (array.size() == 0) {
			return 0;
		}
		vector<int>::iterator ir = array.begin();
		int sum_max_old = *ir;
		int sum_max = *ir;
		for (ir = array.begin() + 1;ir != array.end();ir++) {
			if (sum_max_old < 0) {
				sum_max_old = *ir;
			}
			else {
				sum_max_old = sum_max_old + *ir;
			}
			if (sum_max < sum_max_old) {
				sum_max = sum_max_old;
			}
			else {
				sum_max = sum_max;
			}
		}
		return sum_max;
	}

int main() {
	int arr[] = { 6,-3,-2,7,-15,1,2,2 };
	vector<int> v;
	vector<int>::iterator ir = v.begin();
	ir = v.insert(v.begin(), arr, arr + 8);
	int sum = FindGreatestSumOfSubArray(v);
	cout << sum << endl;
	system("pause");
	return 0;
}