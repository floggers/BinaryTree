#include <iostream>
#include <string>
using namespace std;

string Change_Str(string &src) {
	string str2(src);
	string::iterator its = src.begin();
	for (its;its != src.end();++its) {
	int pos1 = str2.rfind(*its);
	int pos2 = str2.find(*its);
		if (pos1 != pos2) {
			str2.erase(pos1, 1);
			
		}
		else if(pos1==pos2){
			continue;
		}
	}
	return str2;
}

int main() {
	string str1;
	str1.reserve(101);
	getline(cin, str1);
	cout << Change_Str(str1);
	system("pause");
	return 0;
}