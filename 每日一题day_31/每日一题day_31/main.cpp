#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
1月1日                         : 元旦                           2000-01-01 周六
1月的第三个星期一              : 马丁路德金纪念日
2月的第三个星期一              : 总统节
5月的最后一个星期一            : 阵将士纪念日
7月4日                         : 美国国庆
9月的第一个星期一              : 劳动节
11月的第四个星期四             : 感恩节
12月25日                       : 圣诞节
*/
class Solution {
public:
	bool isLeap(int year) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return true;
		}
		else {
			return false;
		}
	}

	int How_manyLeap(int year) {
		int count = 0;
		for (int i = 2000;i < year;++i) {
			if (isLeap(i)) {
				++count;
			}
		}
		return count;
	}

	void Show_holiday(int year) {
		int ret = How_manyLeap(year);
		int days = (year - 2000) * 365 + ret;
		int dif = 0;
		if (isLeap(year)) {
			dif = 1;
		}
		for (int i = 1;i <= 12;++i) {
			int count = 0;
			if (i == 1) {
				for (int j = 1;j <= 31;++j) {
					if (j == 1) {
						cout << year << "-01-01" << endl;
					}
					if ((days + j) % 7 == 3) {
						++count;
					}
					if (count == 3) {
						string str = to_string(j);
						if (str.size() == 1) {
							str = "0" + str;
						}
						cout << year << "-01-" << str << endl;
						break;
					}
				}
			}

			else if (i == 2) {
				for (int j = 32;j <= 59 + dif;++j) {
					if ((days + j) % 7 == 3) {
						++count;
					}
					if (count == 3) {
						string str = to_string(j - 31);
						if (str.size() == 1) {
							str = "0" + str;
						}
						cout << year << "-02-" << str << endl;
						break;
					}
				}
			}

			else if (i == 5) {
				for (int j = 151 + dif;j >= 121 + dif;--j) {
					if ((days + j) % 7 == 3) {
						++count;
					}
					if (count == 1) {
						string str = to_string(j - 120 - dif);
						if (str.size() == 1) {
							str = "0" + str;
						}
						cout << year << "-05-" << str << endl;
						break;
					}
				}
			}

			else if (i == 7) {
				cout << year << "-07-04" << endl;
			}
			else if (i == 9) {
				for (int j = 244 + dif;j <= 273 + dif;++j) {
					if ((days + j) % 7 == 3) {
						++count;
					}
					if (count == 1) {
						string str = to_string(j - 243 - dif);
						if (str.size() == 1) {
							str = "0" + str;
						}
						cout << year << "-09-" << str << endl;
						break;
					}
				}
			}

			else if (i == 11) {
				for (int j = 305 + dif;j <= 334 + dif;++j) {
					if ((days + j) % 7 == 6) {
						++count;
					}
					if (count == 4) {
						string str = to_string(j - 304 - dif);
						if (str.size() == 1) {
							str = "0" + str;
						}
						cout << year << "-11-" << str << endl;
						break;
					}
				}
			}

			else if (i == 12) {
				cout << year << "-12-25" << endl;
			}
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------*/
	bool isprime(int num) {
		for (int i = 2;i <= sqrt(num);++i) {
			if (num%i == 0) {
				return false;
			}
		}
		return true;
	}

	vector<int> Factorization(int num) {       //因式分解
		vector <int> vstr;
		while (num >= 2) {
			if (isprime(num)) {
				vstr.push_back(num);
				break;
			}
			int i = 2;
			for (;i < num;++i) {
				if (isprime(i) && num%i == 0) {
					vstr.push_back(i);
					break;
				}
			}
			num = num / i;
		}
		sort(vstr.begin(), vstr.end());
		return vstr;
	}
};

int main() {
	Solution A;
	//int year;
	//while (cin>>year) {
	//	A.Show_holiday(year);
	//	cout << endl;
	//}
	int num;
	while (cin >> num) {
		vector<int> vi = A.Factorization(num);
		cout << num << " = ";
		for (int i = 0;i < vi.size();++i) {
			cout << vi[i];
			if (i < vi.size() - 1) {
				cout << " * ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}