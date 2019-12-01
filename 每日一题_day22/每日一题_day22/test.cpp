#include <iostream>
#include <string>
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



int main() {

	system("pause");
	return 0;
}

#endif