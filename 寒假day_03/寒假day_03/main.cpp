#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> count;
		for (int i = 0;i < magazine.size();i++) {
			count[magazine[i]] += 1;
		}
		for (int i = 0;i < ransomNote.size();i++) {
			count[ransomNote[i]] -= 1;
			if (count[ransomNote[i]] < 0) {
				return false;
			}
		}
		return true;
	}

	bool canConstruct2(string ransomNote, string magazine) {
		vector<int> hash(26, 0);
		for (int i = 0;magazine[i];i++) {
			hash[magazine[i] - 'a'] += 1;
		}
		for (int i = 0;ransomNote[i];i++) {
			hash[ransomNote[i] - 'a'] -= 1;
			if (hash[ransomNote[i] - 'a'] < 0) {
				return false;
			}
		}
		return true;
	}

	bool isPalindrome(int x) {
		vector<int> num;
		int tmp = x;
		long sum = 0;
		if (x < 0) {
			return false;
		}
		while (x) {
			num.push_back(x % 10);
			x /= 10;
		}
		for (int i = 0;i < num.size();i++) {
			sum = sum * 10 + num[i];
		}
		if (sum != tmp) {
			return false;
		}
		else {
			return true;
		}
	}
};


int main() {
	string str1("abce");
	string str2("abcde");
	Solution A;
//cout<<	A.canConstruct2(str1, str2);
cout << A.isPalindrome(12321);
	system("pause");
	return 0;
}