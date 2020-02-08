#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string buf;
		for (auto i : s) {
			if ((i>='A'&&i<='Z')||(i>='0'&&i<='9')||(i >= 'a'&&i <= 'z')) {
				if (i >= 'A'&&i <= 'Z') {
					i = i + 32;
				}
				buf += i;
			}
		}
		int left = 0;
		int right = buf.size() - 1;
		while (left < right) {
			if (buf[left]==buf[right]){
				left++;
				right--;
			}
			else{
				return false;
			}
		}
		return true;
	}

	int compress(vector<char>& chars) {
		unordered_map<char, int>ret_map;
		int tmp = 0;
		int i = 0;
		for (auto i : chars) {
			ret_map[i]++;
		}
		for (auto i : ret_map) {
			if (i.second == 1) {
				tmp += 0;
			}
			else if (i.second > 1 && i.second < 10) {
				tmp += 1;
			}
			else if (i.second >= 10 && i.second < 100) {
				tmp += 2;
			}
			else if (i.second >= 100 && i.second < 1000) {
				tmp += 3;
			}
		}
		int n = ret_map.size() + tmp;
		while (i < n - 1) {
			if (ret_map[chars[i]] > 1) {
				string s = to_string(ret_map[chars[i]]);
				if (chars.size() - (i + ret_map[chars[i]]) >= 0) {
					chars[i] = chars[ret_map[i]-1];
					for (int k = 0;k < s.size();k++,i++) {
						chars.insert(chars.begin() + i + 1, s[k]);
					}
				}
				i += s.size();
			}
			else {
				chars[i] = chars[i + ret_map[chars[i]] - 1];
				i += 1;
			}
		}
		chars.resize(n);
		return n;
	}

};

int main() {
	string str("`l;`` 1o1 ??;l`");
	char chr[7] = { 'a','a','b','b','c','c','c' };
	vector<char> vecchr(chr, chr + 7);
	Solution A;
	//cout << A.isPalindrome(str);
	cout << A.compress(vecchr);
	system("pause");
	return 0;
}