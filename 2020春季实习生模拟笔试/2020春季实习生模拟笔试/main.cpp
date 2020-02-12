#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
string RmBfromA(string a, string b) {
	string buf;
	int lenb = b.size();
	int lena = a.size();
	for (int i = 0;i < lena;i++) {
		bool sign = true;
		for (int j = 0;j < lenb;j++) {
			if (a[i] == b[j]) {
				sign = false;
				break;
			}
		}
		if (sign == true) {
			buf += a[i];
		}
	}
	return buf;
}

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	cout << RmBfromA(str1, str2)<<endl;
	system("pause");
	return 0;
}

#endif

#if 0

int Max_Sum(vector<int> vit) {
	int sum_old = vit[0];
	int sum = vit[0];
	for (int i = 1;i < vit.size();i++) {
		if (sum_old<0){
			sum_old = vit[i];
		}
		else{
			sum_old = sum_old + vit[i];
		}
		if (sum < sum_old) {
			sum = sum_old;
		}
		else {
			sum = sum;
		}
	}
	return sum;
}

int main() {
	int n;
	int b;
	vector<int> arr;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> b;
		arr.push_back(b);
	}
	cout << Max_Sum(arr) << endl;
	system("pause");
	return 0;
}

#endif

#if 1
//´íÎó´úÂë
bool WaysTo24(vector<int> nums,int result,int pos) {
	int flag = 0;
	if (result == 24) {
		flag = 1;
	}
	else if (result > 24||pos>=4) {
		flag = 0;
	}
	for (int choose = 0;choose < 4;choose++) {
		switch (choose){
		case 0:WaysTo24(nums, pos + 1, result + nums[pos]);break;
		case 1:WaysTo24(nums, pos + 1, result - nums[pos]);break;
		case 2:WaysTo24(nums, pos + 1, result * nums[pos]);break;
		case 3:WaysTo24(nums, pos + 1, result / nums[pos]);break;
		}
	}
	if (flag){
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int a;
	vector<int> v;
	for (int i = 0;i < 4;i++) {
		cin >> a;
		v.push_back(a);
	}
	v.resize(4);
	if (WaysTo24(v, 0,0)) {
		cout << "true" << endl;
	}
	cout << "false" << endl;
	system("pause");
	return 0;
}

#endif