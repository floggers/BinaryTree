#include <iostream>
#include <string>
using namespace std;

void TestString1() {
	string s;                            //����յ�string�����s
	string s1("Hello World!");       //��C��ʽ���ַ�������string�����s1
	string s2(s1);                       //��������s2
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.clear();
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.resize(5, 'x');                   //���ַ�������Ч�ַ������ı䵽5�� ���� ����������ʱ��resize(n)��0���������Ԫ�ؿռ䣬resize(size_t n, char c)���ַ�c��������� Ԫ�ؿռ䡣ע�⣺resize�ڸı�Ԫ�ظ���ʱ������ǽ�Ԫ�ظ������࣬���ܻ�ı�ײ������Ĵ� С������ǽ�Ԫ�ظ������٣��ײ�ռ��ܴ�С���䡣 
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(16);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.resize(8);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void TestString2() {
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << endl;

	s.reserve(50);                         //reserveֻ��������
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
}

void TestString3() {
	string s;
	s.push_back('o');
	s.append("XO");
	s += 'p';
	s += "xo";
	cout << s << endl;
	cout<<s.substr(1, 3)<<endl;
}

int main() {
	//TestString1();
	//TestString2();
	//TestString3();
	system("pause");
	return 0;
}