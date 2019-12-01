#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0

int main() {
	string s;
	int count = 0;
	int signal = 0;
	bool buf = 0;
	while (cin >> s){
		for (int i = s.size() - 1;i >= 0;i--) {
			for (int j = s.size() - 1;j >= 0;j--) {
				if (s[i] == s[j]) {
					count++;
				}
			}
				if (count == 1) {
					signal = i;
					buf = 1;
				}
				count = 0;
		}
		if (buf) {
			cout << s[signal] << endl;
		}
		else {
			cout << -1 << endl;
		}
		buf = 0;
}
	system("pause");
	return 0;
}

#endif

#if 1

int max_Gongy(int c, int b) {
	int min, max;
	int temp;
	min = c > b ? b : c;
	max = c > b ? c : b;
	while (max - min != 0) {
		temp = max - min;
		max = temp > min ? temp : min;
		min = temp > min ? min : temp;
	}
	return max;
}

int main() {
	int n, a;
	while (cin >> n >> a) {
		int c = a;
		vector<int> b(n, 0);
		for (int i = 0;i < n;i++) {
			cin >> b[i];
		}
		for (int i = 0;i < n;i++) {
			if (b[i] <= c) {
				c += b[i];
			}
			else {
				c += max_Gongy(c, b[i]);
			}
		}
		cout << c << endl;
	}
	system("pause");
	return 0;
}

#endif