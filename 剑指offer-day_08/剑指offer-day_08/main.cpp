#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot) {
			return;
		}
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}

	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		int up = 0;  //最上面一行
		int down = row - 1;   //最下面一行
		int left = 0;  //坐左边一列
		int right = col - 1;  //最右边一列
		vector<int> buf;
		while (true) {
			for (int j = left;j <= right;++j) {             //  j->列   i->行
				buf.push_back(matrix[up][j]);
			}
			++up;
			if (up > down)  break;

			for (int i = up;i <= down;++i) {
				buf.push_back(matrix[i][right]);
			}
			--right;

			if (right < left) break;
			for (int j = right;j >= left;--j) {
				buf.push_back(matrix[down][j]);
			}
			--down;
			if (down < up) break;
			for (int i = down;i >= up;--i) {
				buf.push_back(matrix[i][left]);
			}
			++left;
			if (left > right) break;
		}
		return buf;
	}
};

int main() {
	vector<vector<int>> test = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	Solution A;
	for (auto &i : A.printMatrix(test)) {
		cout << i << "  ";
	}
	system("pause");
	return 0;
}