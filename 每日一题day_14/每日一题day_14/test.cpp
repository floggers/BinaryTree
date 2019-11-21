#include <iostream>
#include <vector>
using namespace std;

#if 0

bool isleap(int year) {
	if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0) {
		return true;
	}
	return false;
}

int getOutday(int year, int months, int day) {
	int Outday = 0;
	int days = 0;
	switch (months) {
	case 1:days =  0;break;
	case 2:days = 31;break;
	case 3:days = 59;break;
	case 4:days = 90;break;
	case 5:days = 120;break;
	case 6:days = 151;break;
	case 7:days = 181;break;
	case 8:days = 212;break;
	case 9:days = 243;break;
	case 10:days = 273;break;
	case 11:days = 304;break;
	case 12:days = 334;break;
	default: return -1;
	}
	Outday = days + day;
	if (isleap(year)){
		Outday = Outday + 1;
	}
	if (day > 31 && day < 0) {
		return -1;
	}
	return Outday;
}

int main() {
	int year, months, day;
	/*while (cin >> year >> months >> day) {
		cout << getOutday(year, months, day);
	}*/
	cin >> year >> months >> day;
	cout << getOutday(year, months, day);
	system("pause");
	return 0;
}

#endif

#if 0     //有些许问题
int main()
{
	int yy, mm, dd;
	while (cin >> yy, cin >> mm, cin >> dd) {
		int array[12] = { 0, 31,59,90,120,151,181,212,243,273,304,334 };
		int days = 0;
		days = array[mm - 1];
		days += dd;
		if (mm > 2) {
			if ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0) {
				days += 1;
			}
		}
		cout << days << endl;
	}
	return 0;
}
#endif

#if 1

bool Lucky_or_not(vector<int> v) {
	int num1 = 0;
	int num2 = 0;
	for (int i = 0;i < v.size();i++) {
		num1 += v[i];
		num2 *= v[i];
	}
	if(num1>num2){
		return true;
	}
	else{
		return false;
	}
}

int Solutions_ways(vector<int> v) {
	int ways = 0;
	if (Lucky_or_not(v)) {
		ways++;
	}
	else {
		vector<int>::iterator it1 = v.begin();
		vector<int>::iterator it2 = v.end() - 1;
		for (it1 = v.begin();it1 != v.end();it1++) {
			it1 = v.erase(it1);
			if (Lucky_or_not(v)) {
				ways++;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> vi;
	int num;
	while (cin >> num) {
		vi.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	system("pause");
	return 0;
}

#endif