#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		if (!(s.size())) {
			return 0;
		}
		for (int i = 0;i < s.size();i++) {
			if (s[i] != ' ') {
				count++;
			}
			else if(s[i+1] && i+1<s.size() && s[i+1]!=' '){
				count = 0;
			}
		}
		return count;
	}

	int lengthOfLastWord2(string s) {
	
	}
};

int main() {
	Solution A;
	cout<<A.lengthOfLastWord("b   a    ");

	system("pause");
	return 0;
}