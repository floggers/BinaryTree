#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
int main() {
	string buf;
	while (getline(cin, buf)) {
		for (auto &i : buf) {
			if (i >= '0'&&i <= '9') {
				cout << i;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
#endif

#if 1
void Reach_end(int x, int y, int &count, vector<vector<char>> board) {
	if (x==9&&y==8) {
		return ;
	}
	++count;
	if (board[x+1][y] != '#') {
		Reach_end(x + 1, y,count,board);
	}
	else if (board[x][y + 1] != '#') {
		Reach_end(x , y+1, count, board);
	}
	else if (board[x][y-1] != '#') {
		board[x][y] = '#';
		Reach_end(x, y - 1, count, board);
	}
	else {
		board[x][y] = '#';
		Reach_end(x + 1, y, count, board);
		count = count - 1;
	}
}

int main() {
	vector<vector<char>> board(10, vector<char>(10));
	while (cin>>board[0][0]) {
		int count = 0;
		for (int i = 1;i < 10;++i) {
				cin >> board[0][i];
		}
		for (int i = 1;i < 10;++i) {
			for (int j = 0;j < 10;++j) {
				cin >> board[i][j];
			}
		}
		Reach_end(0, 1, count, board);
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif