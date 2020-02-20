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
private:
	stack<int> stack1;
	stack<int> stack2;
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (!pre.size() && !vin.size()) {
			return nullptr;
		}
		int father = 0;
		TreeNode* root = new TreeNode(pre[0]);
		for (int i = 0;i < vin.size();i++) {
			if (vin[i] == pre[0]) {
				father = i;
				break;
			}
	}
		vector<int> left_pre(pre.begin() + 1, pre.begin()+father+1);
		vector<int>right_pre(pre.begin() + father + 1, pre.end());
		vector<int> left_vin(vin.begin(), vin.begin() + father);
		vector<int>right_vin(vin.begin() + father + 1, vin.end());
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}

	void push(int node) {
		while (stack2.size() > 0) {
			stack1.push(pop());
		}
		stack1.push(node);
		while (stack1.size() > 0) {
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	int pop() {
		int data = stack2.top();
		stack2.pop();
		return data;
	}

};

int main() {
	Solution A;
	vector<int> v1 = { 1,2,4,7,3,5,6,8 };
	vector<int> v2 = { 4,7,2,1,5,3,8,6 };
	A.reConstructBinaryTree(v1, v2);
	system("pause");
	return 0;
}