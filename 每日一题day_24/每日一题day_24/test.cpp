#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 1

class Bonus {
public:
	int getMost(vector<vector<int>> board) {
		int row = board.size();  //ÐÐ
		int col = board[0].size();  //ÁÐ
		vector<vector<int>>dp = board;
		for (int i = 1;i < row;++i) {
			dp[i][0] += dp[i - 1][0];
		}
		for (int j = 1;j < col;++j) {
			dp[0][j] += dp[0][j - 1];
		}
		for (int i = 1;i < row;++i) {
			for (int j = 1;j < col;++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
			}
		}
		return dp[row - 1][col - 1];
	}
};

int main() {
	//...
	system("pause");
	return 0;
}

#endif