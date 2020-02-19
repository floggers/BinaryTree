#include <iostream>
using namespace std;

#if 0

int main() {
	int i = 10;
	int* ret = &i;
	//(*ret)++;
	//cout << "i = " << i << endl;
	//cout << "*ret = " << *ret << endl;
	int j = 20;
	ret = &j;
	(*ret)++;
	cout << "i = " << i << endl;
	cout << "*ret = " << *ret << endl;
	cout << "j = " << j << endl;
	system("pause");
	return 0;
}

#endif


#if 0
int main() {
	int i = 10;
	int & ret = i;
	ret++;
	//cout << "i = " << i << endl;
	//cout << "ret = " << ret << endl;
	int j = 20;
	ret = j;
	ret++;
	cout << "i = " << i << endl;
	cout << "ret = " << ret << endl;
	cout << "j = " << j << endl;
	system("pause");
	return 0;
}

#endif