#include <iostream>
using namespace std;

/******************************************************** 快  排 *******************************************************/
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

/******************************************************** 堆  排 *******************************************************/

//建一个大根堆
void MakeHeap(int* arr, int end) {  //end表示最后一个元素下标
	int last = (end - 1) / 2;  //最后一个非叶子节点的下标
	for (int i = last;i >= 0;--i) {
		int left_son = 2 * i + 1;    //左孩子下标
		int right_son = 2 * i + 2;   //右孩子下标
		int bigson = left_son;       //孩子中值较大的一个下标
		if (right_son <= end&&arr[right_son] > arr[left_son]) {
			bigson = right_son;
		}
		if (arr[bigson] > arr[i]) {
			swap(arr[bigson], arr[i]);
		}
	}
}

void HeapSort(int*arr, int num) {  //num表示元素总数
	for (int i = num - 1;i > 0;--i) {
		MakeHeap(arr, i);
		swap(arr[i], arr[0]);
	}
}

/******************************************************** 归  并 *******************************************************/

int main() {
	int arr[] = { 1,2,0,1,2,1,1,1 };
	//QuickSort(arr, 0, 7);
	HeapSort(arr, 8);
	for (auto &e : arr) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}