#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : 
		val(x),
		left(NULL), 
		right(NULL)
	{}
	
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() && vin.size()) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(pre[0]);
	
		}
		return root;
	}
};

int main() {

	system("pause");
	return 0;
}