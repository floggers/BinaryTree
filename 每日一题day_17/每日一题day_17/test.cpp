#include <iostream>
#include <vector>
using namespace std;

#if 1

int main() {
	int n;
	cin >> n;
	vector<vector<int>> vvi(n, vector<int>(2 * n - 1, 0));
	vvi[0][0] = 1;
	for (int i = 1;i < n;i++) {
		vvi[i][0] = vvi[i][2 * i] = 1;
		for (int j = 1;j < 2 * i;j++) {
			if (j == 1) {
				vvi[i][j] = vvi[i - 1][j] + vvi[i][j - 1];
			}
			else {
				vvi[i][j] = vvi[i - 1][j - 1] + vvi[i - 1][j - 2] + vvi[i - 1][j];
			}
		}
	}
	int j = 0;
	for ( j = 0;j < 2 * n - 1;j++) {
		if (vvi[n - 1][j] % 2 == 0&&vvi[n-1][j]!=0) {
			cout << j + 1 << endl;
			break;
		}
	}
	if (j == 2 * n - 1) {
		cout << -1 << endl;
	}
	system("pause");
	return 0;
}

#endif