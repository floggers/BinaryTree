#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int Cut_paper(string big, string small) {
		int len1 = big.size();
		int len2 = small.size();
		if (len2 > len1) {
			return 0;
		}
		int count = 0;
		while (big.size() >= len2) {
			int pos = big.find(small);
			if (pos == -1 ) {
				return count;
			}
			else {
				++count;
			}
			string buf;
			for (int i = 0;i < big.size();++i) {
				if (i<pos || i>pos + len2 - 1) {
					buf.push_back(big[i]);
				}
			}
			big = buf;
		}
		return count;
	}
/*--------------------------------------------------------------------------------------------------------------------------*/

	vector<long long> Fibo() {
		vector<long long> res;
		res.resize(81);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2;i < 81;++i) {
			res[i] = res[i - 2] + res[i - 1];
		}
		return res;
	}

	long long Breakfast(int day1, int day2) {
		vector<long long> res = Fibo();
		long long sum = 0;
		for (int i = day1;i <= day2;++i) {
			sum += res[i - 1];
		}
		return sum;
	}

};

int main() {
	Solution A;
	//string a, b;	
	//while (cin >> a >> b) {
	//	cout << A.Cut_paper(a, b) << endl;
	//}

	int a, b;
	while (cin >> a >> b) {
		cout << A.Breakfast(a, b) << endl;
	}
	system("pause");
	return 0;
}