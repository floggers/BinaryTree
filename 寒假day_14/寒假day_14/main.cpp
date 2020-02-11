#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int firstUniqChar(string s) {
		int i = 0;
		int HashTable[26] = { 0 };
		string::iterator strit = s.begin();
		while (strit != s.end()) {
			HashTable[*strit - 'a']++;
			strit++;
		}
		strit = s.begin();
		while (strit != s.end()) {
			if (HashTable[*strit - 'a'] == 1) {
				return i;
			}
			strit++;
			i++;
		}
		return -1;
	}

	vector<int> rightSideView(TreeNode* root) {

	}

};

int main() {
	string str("loveleetcode");
	Solution A;
	//cout << A.firstUniqChar(str);
	system("pause");
		return 0;
}