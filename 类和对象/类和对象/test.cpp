#include <iostream>
using namespace std;

class Test
{
public:
	Test(int, int, int) {
		cout << "Test" << endl;
	};
private:
	int x;
	int y;
	int z;
};
class Mytest
{
public:
	Mytest() :test(1, 2, 3) {       //��ʼ��
		cout << "Mytest" << endl;
	};
private:
	Test test; //����
};
int main()
{
	Mytest test;
	system("pause");
	return 0;
}