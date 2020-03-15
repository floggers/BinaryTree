#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> buf;
		for (auto &e : numbers) {
			buf[e]++;
		}
		int len = numbers.size() / 2;
		for (auto &i : buf) {
			if (i.second >len) {
				return i.first;
			}
		}
		return 0;
	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size() || k == 0) {
			return vector<int>(0);
		}
		vector<int> res;
		multiset<int> buf(input.begin(), input.end());
		for (auto &i : buf) {
			res.push_back(i);
			int len = res.size();
			if (len == k) {
				break;
			}
		}
		return res;
	}
};

int main() {
	Solution A;
	vector<int> v = { 1,2,3,2,2,2,5,2 };
	cout << A.MoreThanHalfNum_Solution(v) << endl;
	
	system("pause");
	return 0;
}