#include <iostream>
#include <vector>

using namespace std;

int res = 0;
int perm(vector<int> board, int low, int high) {
	if (low == high) {
		++res;
	}
	else {
		for (int i = low;i <= high;++i) {
			if (i + 1 <= high&&board[i] == board[i + 1]) {
				continue;
			}
			swap(board[i], board[low]);
			perm(board, low + 1, high);
			swap(board[i], board[low]);
		}
	}
	res = res % 998244353;
	return res;
}


int main() {
	int N, a, b, c, d;
	vector<int> board;
	while (cin >> N >> a >> b >> c >> d) {
		while (a) {
			board.push_back(1);
			--a;
		}
		while (b) {
			board.push_back(2);
			--b;
		}
		while (c) {
			board.push_back(3);
			--c;
		}
		while (d) {
			board.push_back(4);
			--d;
		}
		int high = N*N - 1;
		cout << perm(board, 0, high) << endl;
		res = 0;
	}
	system("pause");
	return 0;
}