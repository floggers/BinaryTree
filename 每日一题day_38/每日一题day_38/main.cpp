#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void Reach_Black(int x,int y,int& count,vector<vector<char>> form) {
		if (x<0 || x>=form.size() || y<0 || y>=form[0].size() || form[x][y] == '#') {
			return;
		}
		++count;
		form[x][y] = '#';
		Reach_Black(x - 1, y, count, form);
		Reach_Black(x + 1, y, count, form);
		Reach_Black(x, y - 1, count, form);
		Reach_Black(x, y + 1, count, form);
	}
};

int main() {
	Solution A;
	int row, col, x, y;
	while (1) {
		int count = 0;
		cin >> row >> col;
		vector<vector<char>> res;
		res.resize(row,vector<char>(col));
		for (int i = 0;i < row;++i) {
			for (int j = 0;j < col;++j) {
				cin >> res[i][j];
				if (res[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}
		A.Reach_Black(x, y, count, res);
		cout << count << endl;
	}
	system("pause");
	return 0;
}