#include <iostream>
using namespace std;

class Solution {
public:
	void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void QuickSort(int* array,int left,int right) {
		if (left == right) {
			return;
		}
		int start = left;
		int end = right;
		int key = left;
		while (left < right) {
			if (array[right] <= array[key]) {
				swap(&array[right], &array[key]);
				--right;
				continue;
			}
			else {
				--right;
				continue;
			}
			if (array[left] > array[key]) {
				swap(&array[left], &array[key]);
				++left;
				continue;
			}
			else {
				++left;
				continue;
			}
		}
		right = right + 1;
		QuickSort(array, start, left);
		QuickSort(array, right, end);
	}
};

int main() {
	int arr[] = { 6,3,1,5,4,7,9,8 };
	Solution A;
	A.QuickSort(arr, 0, 7);
	for (auto& i : arr) {
		cout << i << "  ";
	}
	system("pause");
	return 0;
}