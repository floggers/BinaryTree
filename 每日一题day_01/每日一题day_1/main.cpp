#include <iostream>
using namespace std;

#if 0
void select_sort(int* src, int size) {
	for (int i = 0;i < size - 1;i++) {
		int Min = i;
		for (int j = i + 1;j < size;j++) {
			if (src[Min] > src[j]) {
				Min = j;
			}
		}
		if (Min != i) {
			int tmp = src[Min];
			src[Min] = src[i];
			src[i] = tmp;
		}
	}
}

long Average_max(int* src, int size) {
	select_sort(src, size);
	long average_max = 0;
	if (size % 3 != 0) {
		return 0;
	}
	else {
		for (int i = 0;i < size / 3;i++) {
			average_max += src[size / 3+i*2];
		}
	}
	return average_max;
}

int main() {
	/*int n;
	int a_i;
	int member[256] = { 0 };
	cout << "请输入队伍总数n:" << endl;
	cin >> n;
	cout << "请输入3*n个水平值(int):" << endl;
	for (int i = 0;i < 3 * n;i++) {
		cin >> a_i;
		member[i] = a_i;
	}
	int outcome=Average_max(member, 3 * n);
	cout << outcome << endl;*/
	int n;
	while (cin >> n) {
		int *arr = new int[3 * n];
		int i = 0;
		for (; i < 3 * n; i++) {
			cin >> arr[i];
		}
		cout << Average_max(arr, 3 * n);
		system("pause");
		return 0;
	}
}
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int *arr = new int[3 * n];
		int i = 0;
		for (; i < 3 * n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 3 * n);
		long sum = 0;
		int j = 1;
		while (j <= n) {
			sum += arr[3 * n - 2 * j];
			j++;
		}
		cout << sum << endl;
	}
	return 0;
}
#endif

#if 1
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
	string str3;
	char n=0,m=0;
	while (1) {
		n = getchar();
		if (n == '\n') {
			break;
		}
		str1.push_back(n);
	}
	while (1) {
		m = getchar();
		if (m == '\n') {
			break;
		}
		str2.push_back(m);
	}
	bool sign = true;
	string::iterator it1 = str1.begin();
	string::iterator it2;
	for (it1;it1 != str1.end();++it1) {
		for (it2=str2.begin();it2 != str2.end();++it2) {
			if (*it1 == *it2) {
				sign = false;
				break;
			}
		}
		if (sign==true){
			str3.push_back(*it1);
		}
		sign = true;
	}
	cout << str3.c_str() << endl;
		system("pause");
		return 0;
}
#endif