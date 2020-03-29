#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	/***********************************************��     ��***********************************************************/

	void QuickSort(int* array,int left,int right) {                 //����
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

/***********************************************��     ��***********************************************************/

	void HeapSort(int* array, int num) {         //num��ʾԪ���ܸ���
		for (int i = num - 1;i > 0;--i) {
			MakeHeap(array, i);
			swap(&array[0], &array[i]);
		}
	}

	void MakeHeap(int* array, int end) {           //end��ʾ���һ��Ԫ���±�
		int len = (end - 1) / 2;                 //len��ʾ���һ����Ҷ�ӽڵ���±�
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
	// ������array�е�Ԫ�ع���set   
	vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(v.begin(), v.end());
	//for (int i : arr) {
	//	s.insert(i);
	//}
	cout << s.size() << endl;

	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��  
	for (auto& e : s)
		cout << e << " ";    cout << endl;

	// ʹ�õ����������ӡset�е�Ԫ�� 
	for (auto it = s.rbegin(); it != s.rend(); ++it)        cout << *it << " ";    cout << endl;

	// set��ֵΪ3��Ԫ�س����˼���   
	cout << s.count(3) << endl;
}

void test(string s) {
	cout << s;
}
#define STR "888"

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