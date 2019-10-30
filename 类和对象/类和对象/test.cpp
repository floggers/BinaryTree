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
	Mytest() :test(1, 2, 3) {       //³õÊ¼»¯
		cout << "Mytest" << endl;
	};
private:
	Test test; //ÉùÃ÷
};
int main()
{
	Mytest test;
	system("pause");
	return 0;
}