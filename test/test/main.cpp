#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
	void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	/***********************************************快     排***********************************************************/

	void QuickSort(int* array,int left,int right) {                 //快排
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

/***********************************************堆     排***********************************************************/

	void HeapSort(int* array, int num) {         //num表示元素总个数
		for (int i = num - 1;i > 0;--i) {
			MakeHeap(array, i);
			swap(&array[0], &array[i]);
		}
	}

	void MakeHeap(int* array, int end) {           //end表示最后一个元素下标
		int len = (end - 1) / 2;                 //len表示最后一个非叶子节点的下标
		for (int i = len;i >= 0;--i) {
			int leftson = 2 * i + 1;
			int rightson = 2 * i + 2;
			int big_sig = leftson;
			if (rightson <= end&&array[rightson] > array[leftson]) {
				big_sig = rightson;
			}
			if (array[big_sig] > array[i]) {
				swap(&array[big_sig], &array[i]);
			}
		}
	}

/*****************************************************************************************************************/

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size()|| k==0) {
			return vector<int>(0);
		}
		vector<int> res;
		multiset<int> buf(input.begin(), input.end());
		for (auto &i : buf) {
			res.push_back(i);
			int len = res.size();
			if (len == k) {
				break;
			}
		}
		return res;
	}



};

void TestSet() {
	// 用数组array中的元素构造set   
	vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(v.begin(), v.end());
	//for (int i : arr) {
	//	s.insert(i);
	//}
	cout << s.size() << endl;

	// 正向打印set中的元素，从打印结果中可以看出：set可去重  
	for (auto& e : s)
		cout << e << " ";    cout << endl;

	// 使用迭代器逆向打印set中的元素 
	for (auto it = s.rbegin(); it != s.rend(); ++it)        cout << *it << " ";    cout << endl;

	// set中值为3的元素出现了几次   
	cout << s.count(3) << endl;
}

void test(string s) {
	cout << s;
}
#define STR "888"
/*
int main() {
	 vector<int> v = { 4,5,1,3,7,6,8,2,9 };
	 int arr[] = { 8,7,6,5,4,3,2,1 };
	 Solution A;
	//A.QuickSort(arr, 0, 7);
	//TestSet();
	 //A.HeapSort(arr, 8);
	 //for (auto &i:arr) {
	 //	 cout << i << ' ';
	 //}
	 test(STR);
	 system("pause");
	 return 0;
}
*/
#define N 100
int length;
void findsum(int n, int *p, int m){
	if (n < 1 || m < 1){
		return;
	}
	if (n > m){
		n = m;
	}
	if (n == m){
		p[n - 1] = 1;
		for (int i = 0; i < length; i++){
			if (p[i] == 1){
				printf("%d  ", i + 1);
			}
		}
		printf("\n");
		p[n - 1] = 0;
	}
	p[n - 1] = 1;
	findsum(n - 1, p, m - n);
	p[n - 1] = 0;
	findsum(n - 1, p, m);
}

class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.size() == 1) {
			return numbers[0];
		}
		else if (numbers.size() == 0) {
			return -1;
		}
		int size = numbers.size();
		numbers.insert(numbers.end(), numbers.begin(), numbers.end());
		int count = 0;
		for (int i = 0;i < numbers.size() - 1;++i) {
			if (numbers[i] <= numbers[i + 1]) {
				++count;
			}
			else {
				count = 0;
			}
			if (count == size-1) {
				return numbers[i - size +2];
			}
		}
		return 0;
	}
};

int main(){
	/*int n, m;
	printf("请输入n=\n");
	scanf("%d", &n);
	length = n;
	printf("请输入m=\n");
	scanf("%d", &m);
	int *p;
	p = (int *)malloc(sizeof(int)*n);
	findsum(n, p, m);*/
	vector<vector<int>> vvit(3, vector<int>(2, 0));
	for (auto &e : vvit) {
		for (auto &i : e) {
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
	
}

