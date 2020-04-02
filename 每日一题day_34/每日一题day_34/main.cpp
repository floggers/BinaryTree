#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
using namespace std;

struct  ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :
		val(x),
		next(nullptr){
	}
};

class Solution {
public:
	/*vector<int> Message_stream(int n, vector<int> arr) {
		vector<int> res;
		vector<int> buf;
		
	}*/

	long long Rabbit(int n) {
		long long *arr = new long long[n + 1];
		arr[0] = 1;
		arr[1] = 2;
		for (int i = 2;i < n;++i) {
			arr[i] = arr[i - 2] + arr[i - 1];
		}
		return arr[n - 1];
		delete[] arr;
	}

};

void test() {
	pair<int, int> p(5, 6);
	vector<int> v = { 4,3,2,6,7 };
	map<int, int> test;
	test.insert(p);
	for (auto &i : v) {
		//cout << i.first<< " " << i.second <<  endl;
		test[i];
	}
	for (auto &i : test) {
		cout << i.first << " " << i.second << endl;
	}
}

int main() {
	Solution A;
	//test();

	//int n;
	//while (cin >> n) {
	//	cout << A.Rabbit(n) << endl;
	//}

	int n;
	cin >> n;
	int Min = 1, k = 1;
	/*vector<int> a;
	a.resize(n);*/
	int *a = new int[n];
	priority_queue<int, vector<int>, greater <int>> q;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		q.push(a[i]);
		if (a[i] == Min)
			while (q.top() == Min) {
				cout << k++ << " " << a[i] << endl;
				Min++;
				q.pop();
			}
	}
	delete[] a;
	system("pause");
	return 0;
}