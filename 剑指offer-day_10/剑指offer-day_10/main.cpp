#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {    //层序遍历 从上往下
		vector<int> res;
		queue<TreeNode*> buf;
		buf.push(root);
		while (!buf.empty()) {
			TreeNode *cur = buf.front();
			res.push_back(cur->val);
			if (cur->left) {
				buf.push(cur->left);
			}
			if (cur->right) {
				buf.push(cur->right);
			}
			buf.pop();
		}
		return res;
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {      //层序遍历  从下往上 
		vector<vector<int>> res;
		queue<TreeNode*> buf;
		buf.push(root);
		while (!buf.empty()) {
			TreeNode *cur = buf.front();
			res.insert(res.begin(), vector<int>(cur->val));
			if (cur->left) {
				buf.push(cur->left);
			}
		}
	}
	
	bool VerifySquenceOfBST(vector<int> sequence) {        //判断二叉搜索树的后序遍历的序列
		if (!sequence.size()) {
			return false;
		}
		return helpVerify(sequence, 0, sequence.size() - 1);
	}

	bool helpVerify(vector<int> sequence, int start, int end) {
		if (start >= end) {
			return true;
		}
		int root = sequence[end];
		int i;
		for (i = start;i < end;++i) {
			if (sequence[i] > root) {
				break;
			}
		}
		for (int j = i;j < end;++j) {
			if (sequence[j] < root) {
				return false;
			}
		}
		return helpVerify(sequence, start, i - 1) && helpVerify(sequence, i, end - 1);
	}

};

int main() {

	system("pause");
	return 0;
}