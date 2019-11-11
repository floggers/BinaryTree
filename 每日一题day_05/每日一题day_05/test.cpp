#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0

int Function(string &s1, string &s2) {
	int num2 = s2.size();
	int num = s1.size() +1;
	int func_num = 0;
	string::iterator it1 = s1.begin();
	string::iterator it2 = s1.end();
	for (int i = 0;i < num;i++) {
		int count = 0;
		s1.insert(i, s2);
		it1 = s1.begin();
		it2 = s1.end();
		while (it1 < it2-1) {
			if (*it1 == *(it2-1)) {
				it1++;
				it2--;
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == s1.size() / 2) {
			func_num++;
		}
		s1.erase(i,num2);
		it1 = s1.begin();
		it2 = s1.end();
	}
	return func_num;
}

int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin,s2);
	cout << Function(s1, s2);
	system("pause");
	return 0;
}

#endif

#if 1

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
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}
		vector<int> v;
		vector<int>::iterator ir = v.begin();
		ir = v.insert(v.begin(), p, p + n);
		int sum = FindGreatestSumOfSubArray(v);
		cout << sum << endl;
		system("pause");
		return 0;
	}
#endif