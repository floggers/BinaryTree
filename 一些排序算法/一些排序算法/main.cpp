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

void merge(int* ans, int start, int middle, int end) {
	int* res = new int[end - start + 1];
	int i = start, j = middle + 1;
	int p = 0;
	while (i <= middle&&j <= end) {
		res[p++] = ans[i] < ans[j] ? ans[i++] : ans[j++];
	}
	while (i <= middle) {
		res[p++] = ans[i++];
	}
	while (j <= end) {
		res[p++] = ans[j++];
	}
	for (int m = 0, n = start;n <= end;++m, ++n) {
		ans[n] = res[m];
	}
	//delete[] res;
}

void MergeSort(int* ans, int start, int end) {
	if (start == end) {
		return;
	}
	int middle = (end + start) / 2;
	MergeSort(ans, start, middle);
	MergeSort(ans, middle + 1, end);
	merge(ans, start, middle, end);
	
}

/********************************************************选择排序*******************************************************/

void SelectSort(int* arr, int size) {
	for (int i = 0;i < size - 1;++i) {
		int Min = i;
		for (int j = i + 1;j < size;++j) {
			if (arr[j] < arr[Min]) {
				Min = j;
			}
		}
		if (Min != i) {
			swap(arr[i], arr[Min]);
		}
	}
}


int main() {
	int arr[] = { 1,2,3,4,5,6,7,8 };
	//QuickSort(arr, 0, 7);
	//HeapSort(arr, 8);
	//SelectSort(arr, 8);
	MergeSort(arr, 0, 7);
	for (auto &e : arr) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}