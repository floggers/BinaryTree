#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isPrime(int num) {
		if (num == 1) {
			return false;
		}
		for (int i = 2;i <= sqrt(num);++i) {
			if (num%i == 0) {
				return false;
			}
		}
		return true;
	}

	bool isLeap(int year) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return true;
		}
			return false;
	}

	int oneYear_income(int year,int month1,int day1,int month2,int day2) {
		int profit = 0;
		for (int i = month1;i <month2;++i) {
			int dif = 28;
			if (isLeap(year)) {
				dif = 29;
			}
			switch (i) {
			case 1:profit += 31 * 2;   break;
			case 2:profit += dif;	   break;
			case 3:profit += 31;       break;
			case 4:profit += 30 * 2;   break;
			case 5:profit += 31;       break;
			case 6:profit += 30 * 2;   break;
			case 7:profit += 31;       break;
			case 8:profit += 31 * 2;   break;
			case 9:profit += 30;       break;
			case 10:profit += 31 * 2;  break;
			case 11:profit += 30;      break;
			}
		}
		if (isPrime(month2)) {
			profit += day2;
		}
		else {
			profit += (day2 * 2);
		}
		if (isPrime(month1)) {
			profit =profit- (day1-1);
		}
		else {
			profit =profit - ((day1-1) * 2);
		}
		return profit;
	}

	int Income(int year1, int month1, int day1, int year2, int month2, int day2) {
		int profit = 0;
		if (year2 > year1){
			for (int i = year1;i < year2;++i) {
				if (i == year1) {
					profit += oneYear_income(year1, month1,day1,12,31);
				}
				else {
					profit += oneYear_income(i, 1,1,12,31);
				}
			}
		    profit += oneYear_income(year2, 1,1,month2,day2);
		}
		else if(year1==year2){
			profit += oneYear_income(year1, month1,day1,month2,day2);
			}
		return profit;
	}

/*-------------------------------------------------------------------------------------------------------------------------------*/

	string Add(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		if (len1 > 6)  num1 = num1.substr(len1 - 6);
		if (len2 > 6)  num2 = num2.substr(len2 - 6);
			int dif = num1.size() - num2.size();
			if (dif < 0) {
				dif = len2 - len1;
				num1.insert(0, dif, '0');
			}
			else {
				num2.insert(0, dif, '0');
			}
	
		int step = 0;  //½øÎ»
		for (int i = num1.size() - 1;i >= 0;--i) {
			num1[i] = (num1[i] - '0') + (num2[i] - '0') + step;
			if (num1[i] > 9) {
				num1[i] = num1[i] - 10 + '0';
				step = 1;
			}
			else {
				num1[i] = num1[i] + '0';
				step = 0;
			}
		}
		if (step) {
			num1.insert(0, "1");
		}
		return num1;
	}


	vector<string> Fib(int n) {
	//	n = 100000;
		vector<string> ret;
		ret.resize(n+1);
		ret[0] = "1";
		ret[1] = "2";
		for (int i = 2;i < n;++i) {
			ret[i] = Add(ret[i - 2] ,ret[i - 1]);
		}
		//cout << ret[n - 3] << "  +  " << ret[n - 2] << "  =  "<<ret[n-1]<< endl;
		return ret;
	}

	vector<string> solution() {
		Solution B;
		vector<string> ret;
		ret.resize(100000 + 1);
		ret[0] = "1";
		ret[1] = "2";
		for (int i = 2;i < 100000;++i) {
			ret[i] = Add(ret[i - 2], ret[i - 1]);
		}
		return ret;
	}

/*-----------------------------------------------------------------------------------------------------------------------------*/

	void testAdd() {
		/*	string c("123456789");
		cout << c.substr(c.size()-6);*/
		string a, b;
		while (cin >> a >> b) {
			cout << Add(a, b) << endl;
		}
	}

	void test() {
		string a;
		a = 1 + 1;
		cout << a;
	}

};
int main() {
	Solution A;
	 int year1, month1, day1, year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
		cout << A.Income(year1, month1, day1, year2, month2, day2) << endl;
	}


	/*vector<string> ret = A.solution();
	int num;
	while (cin >> num) {
        int size = ret[num-1].size();
		if (size <= 6) {
			ret[num-1] = ret[num-1];
		}
		else {
			ret[num-1]=ret[num-1].substr(size-6);
		}
		cout <<ret[num-1] << endl;
	}*/

	//A.testAdd();

	//A.test();
	system("pause");
	return 0;
}