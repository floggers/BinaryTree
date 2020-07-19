#include <iostream>
using namespace std;

/******************************************************** ¿ì  ÅÅ *******************************************************/
void QuickSort(int* arr, int left, int right) {
	if (left >= right) return;
	int start = left;
	int end = right;
	//int tmp = 0;
	int privot = arr[left];
	while (left < right) {
		while (arr[right] >= privot && left < right) {
			--right;
		}
		while (arr[left] <= privot && left < right) {
			++left;
		}
		if (left < right) {
			/*int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;*/
			swap(arr[left], arr[right]);
		}
	}
	arr[start] = arr[left];
	arr[left] = privot;
	QuickSort(arr, start, left-1);
	QuickSort(arr, right+1, end);
}

/******************************************************** ¶Ñ  ÅÅ *******************************************************/


/******************************************************** ¹é  ²¢ *******************************************************/

int main() {
	int arr[] = { 1,2,0,1,2,1,1,1 };
	QuickSort(arr, 0, 7);
	for (auto &e : arr) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}