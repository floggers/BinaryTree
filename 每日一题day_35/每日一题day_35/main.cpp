#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

	double no_Reward(int n) {
		double sum = 1.0;
		for (int i = n;i >= 2;--i) {
			sum *= i;
		}
		double arr[21] = { 0.0 };
		arr[0] = 0.0;
		arr[1] = 0.0;
		arr[2] = 1.0;
		for (int i = 3;i < 21;++i) {
			arr[i] = (i - 1)*(arr[i - 2] + arr[i - 1]);
		}
		sum = (arr[n] * 100) / sum;
		return sum;
	}

/*--------------------------------------------------------------------------------------------------------------------------------*/

	//bool isSame(string src, string dst) {
	//	int len1 = src.size();
	//	int len2 = dst.size();
	//	if (len1 != len2) {
	//		return false;
	//	}
	//	for (int i = 0;i < len1;++i) {
	//		if (src[i] != dst[i]) {
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	bool isImportan_mail(string list, string name) {
		vector<string> res;
		string buf;
		bool flag = false;
		int len = list.size();
		for (int i = 0;i < len;++i) {
			if (list[i] == '"') {                            //"Letendre, Bruce",Joe,"Quan, William"
				if (!buf.empty()) {                          
					res.push_back(buf);
					buf.clear();
				}
				flag = !flag;
				continue;
			}
			if (flag) {
				buf.push_back(list[i]);
				continue;
			}
			else {
				while (list[i] != ',') {
					buf.push_back(list[i]);                     //Joe,Kewell,Leon
						++i;
						if(i==len) break;
				}
				if (!buf.empty()) {
					--i;
					res.push_back(buf);
					buf.clear();
				}
			}
		}
		for (int i = 0;i < res.size();++i) {
			/*if (isSame(res[i],name)) {
				return false;
			}*/
			if (res[i] == name) {
				return false;
			}
		}
		return true;
	}

};

int main() {
	Solution A;
	/*int n;
	while (cin >> n) {
		printf("%.2f%c\n", A.no_Reward(n), '%');
	}*/
	string list, name;
	while (1) {
		getline(cin, list);
		getline(cin, name);
		if (A.isImportan_mail(list, name)) {
			cout << "Important!"<< endl;
		}
		else {
			cout << "Ignore" << endl;
		}
	}

/*----------------------------------------------抄送列表(On)-------------------------------------------------------------------*/
		string str, name;
		while (getline(cin, str))
		{
			getline(cin, name);
			//接下来把抄送列表分割
			vector<string>v;
			for (size_t i = 0;i < str.size();i++)
			{
				if (str[i] == '\"') {//处理有引号的部分
					v.push_back(str.substr(i + 1, str.find('\"', i + 1) - i - 1));
					i = str.find('\"', i + 1) + 1;
				}
				else {//处理非引号部分
					if (str.find(',', i) == str.npos) {
						v.push_back(str.substr(i, str.size() - i));
						i = str.size();
					}
					else {//没到结束
						v.push_back(str.substr(i, str.find(',', i) - i));
						i = str.find(',', i);
					}
				}
			}
			cout << ((find(v.begin(), v.end(), name) != v.end()) ? "Ignore" : "Important!") << endl;
		}
		return 0;
	system("pause");
	return 0;
}