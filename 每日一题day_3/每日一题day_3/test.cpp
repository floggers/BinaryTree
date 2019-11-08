#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#if 0
string LongNum(const string& src) {
	string ret;
	int i = 0;
	int max = 0;
	while (i < src.size()) {
		int len = 0;
		string buf;
		while (isdigit(src[i])) {
			buf += src[i];
			i++;
			len++;
		}
		if (len > max) {
			ret = buf;
			max = len;
		}
		/*else if (len == max) {
			for (int i = 0;i < len;i++) {
				if (buf[i] > ret[i]) {
					ret = buf;
					break;
				}
			}
		}
		else {
			ret = buf;
		}*/
		i++;
	}
	return ret;
}

int main() {
	string str;
	getline(cin, str);
	cout << LongNum(str)<<endl;
	system("pause");
	return 0;
}

#endif

#if 1

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (!numbers.size()) {
			return 0;
		}
		sort(numbers.begin(), numbers.end() - 1);
		int buf = numbers[0];
		int times = 1;
		int _times = 0;
		for (int i = 0;i < numbers.size() - 1;i++) {
			if (numbers[i + 1] != buf) {
				_times = 0;
				_times++;
				buf = numbers[i + 1];
			}
				if (numbers[i + 1] == buf){
					_times++;
				}
				if (_times >= times) {
					buf = numbers[i + 1];
					times = _times;
				}
			}
		if (times > numbers.size() / 2) {
			return buf;
		}
		else
		{
			return 0;
		}
	}
};

int main() {
	vector<int> array;
	int outcome;
	int num;
	while (cin >> num) {
		array.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	Solution A;
	outcome=A.MoreThanHalfNum_Solution(array);
	cout << outcome;
	system("pause");
	return 0;
}

#endif