#include <iostream>
using namespace std;

#if 0

void conversion_num(char* p, int m, int n) {
	int buf;
	while (m > 0) {
		buf = m%n;
		if (buf < 10) {
			*p = buf + 48;
		}
		else {
			*p = buf + 55;
		}
		m = m / n;
		p++;
	}
	*p = '\0';
}


int main() {
	char a[32] = { 0 };
	int M, N;
	cin >> M;
	cin >> N;
	if (M<=0||N == 0) {
		return 0;
	}
	else {
		conversion_num(a, M, N);
		for (int i = strlen(a) - 1;i >= 0;i--) {
			cout << a[i];
		}
	}
	system("pause");
	return 0;
}
#endif

#if 1

int main() {
	int x, y, m, n;
	cin >> x >> y >> m >> n;
	if ((y + n) == (m - x)) {
		cout << (x + m) / 2 << ' ' << (y + n) / 2 << ' ' << (n - y) / 2;
}
	else {
		cout << "No";
	}
	system("pause");
	return 0;
}

#endif