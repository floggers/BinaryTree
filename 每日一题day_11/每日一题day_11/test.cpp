#include <iostream>
using namespace std;

#if 1

class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b) {
			if (a > b) {
				a /= 2;
			}
			else {
				b /= 2;
			}
		}
		return a;
	}
};

int main() {
	LCA A;
	int a, b;
	cin >> a >> b;
	cout << A.getLCA(a, b);
	system("pause");
	return 0;
}

#endif