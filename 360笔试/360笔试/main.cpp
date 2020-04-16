#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#if 1

int main() {
	int n;
	while (cin >> n) {
		int *a = new int[n+1];
		cin >> a[0];
		int res = 0;
		int count = 0;
		for (int i = 1;i <= n;++i) {
			for (int j = 0;j <= a[i-1];++j) {
				a[i] = a[i - 1] - j;
				if (a[i] == 0) {
					++res;
				}
				++count;
			}
		}
		printf("%.5f\n", res / count);
	}
	system("pause");
	return 0;
}

#endif



#if 0
int main() {
	int n, m;
	while (cin >> n) {   //人数
		cin >> m;    //连赢场数
		if (n == 0 || m == 0) {
			return 0;
		}
		queue<int> qu1;
		queue<int> qu2;
		for (int i = 0;i < n;++i) {
			int num;
			cin >> num;
			qu1.push(num);
		}
		int win = 0;
		int count = 0;
		qu2.push(qu1.front());
		qu1.pop();
		while (!qu1.empty()) {
			if (qu2.front() < qu1.front()) {
				qu2.push(qu1.front());
				qu1.pop();
				int min = qu2.front();
				qu2.pop();
				qu1.push(min);
				win = 0;
				++win;
				++count;
			}
			else  if (qu2.front() > qu1.front()) {
				int min = qu1.front();
				qu1.pop();
				qu1.push(min);
				++win;
				++count;
				if (win == m) {
					break;
				}
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}

#endif