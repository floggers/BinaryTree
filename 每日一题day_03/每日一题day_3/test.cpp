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
	//void select_sort(vector<int> &v) {
	//	for (int i = 0;i < v.size() - 1;i++) {
	//		int Max = i;                       //刚开始时将i的值赋给了Max
	//		for (int j = i + 1;j < v.size();j++) {
	//			if (v[Max] > v[j]) {   //如果比较出来了下标为j的元素的值大于下标为Max的元素的值
	//				Max = j;               //就将j赋值给Max
	//			}
	//		}
	//		if (Max != i) {    //如果Max不等于i则说明第i大的数字不在第i大的位置上 所以要交换
	//			int tmp = v[Max];
	//			v[Max] = v[i];
	//			v[i] = tmp;
	//		}
	//	}
	//}

	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//	if (numbers.size()==0) {
		//		return 0;
		//	}
		//	else {
		//		//select_sort(numbers);
		//		sort(numbers.begin(), numbers.end());
		//		int buf = numbers[0];
		//		int times = 0;
		//		int _times = 0;
		//		int tmp = 0;
		//		for (int i = 0;i < numbers.size() ;i++) {
		//			if (numbers[i + 1] == buf) {
		//				times++;
		//				tmp = times;
		//			}
		//			else {
		//				buf = numbers[i + 1];
		//				_times++;
		//				tmp = times > tmp ? times : tmp;
		//				times = 0;
		//			}
		//			if (_times >= times) {
		//				times = _times;
		//				_times = 0;
		//			}
		//		}
		//		if (tmp>(numbers.size() / 2)) {
		//			return numbers[numbers.size()/2];
		//		}
		//		else
		//		{
		//			return 0;
		//		}
		//	}
		//}
		sort(numbers.begin(), numbers.end());
		int count = 0;
		int key = numbers[numbers.size() / 2];
		for (int i = 0;i < numbers.size();i++) {
			if (key == numbers[i]) {
				count++;
			}
		}
		if (count > (numbers.size() / 2)) {
			return key;
		}
		return 0;
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