#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#if 0

int Func(int a, int b) {
	int outc = 0;
	int min, max,temp;
	min = a > b ? b : a;
	max = a > b ? a : b;
	while (max - min != 0) {
		temp = max - min;
		max = temp > min ? temp : min;
		min = temp > min ? min : temp;
	}
	outc = a*b / max;
	return outc;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << Func(a, b);
	system("pause");
	return 0;
}

#endif

#if 1

int which_Sort_case(vector<string> vs) {
	int flag = 0;
	vector<string> vs_buf(vs);      
	vector<int> vi_buf;
	for (int i = 0;i < vs.size();i++) {
		vi_buf.push_back(vs[i].size());
	}
	sort(vs_buf.begin(), vs_buf.end());       //×ÖµäÐòÅÅÐò
	sort(vi_buf.begin(), vi_buf.end());      //³¤¶ÈÅÅÐò
	for (int i = 0;i < vs.size();i++) {
		if (vs[i] != vs_buf[i]) {
			if (vs[i].size() == vi_buf[i]) {
				flag = 2;  //°´ÕÕ³¤¶ÈÅÅÐò   lengths
			}
			else {
				flag = 4;  //  none
			}
		}
			if (vs[i].size() != vi_buf[i]) {
				if (vs[i] == vs_buf[i]) {
					flag = 1;
				}
				else {
					flag = 4;
				}
			}
			if (vs[i] == vs_buf[i] && vs[i].size() == vi_buf[i]) {
				if (flag != 2&&flag!=1) {
					flag = 3;
				}
			}
	}
	return flag;
}

int main() {
	int swh;
	string s;
	vector<string> vs;
	int n;
	cin >> n;
	while (cin >> s) {
		vs.push_back(s);
		n--;
		if (n == 0) {
			break;
		}
	}
	swh = which_Sort_case(vs);
	switch (swh)
	{
	case 1:cout << "lexicographically" << endl; break;
	case 2:cout << "lengths" << endl;break;
	case 3:cout << "both" << endl;break;
	case 4:cout << "none" << endl;break;
	default:cout << "ÊäÈë´íÎó£¡" << endl;break;
	}
	system("pause");
	return 0;
}

#endif 
