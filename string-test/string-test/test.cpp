#include <iostream>
#include <string>
using namespace std;

void TestString1() {
	string s;                            //构造空的string类对象s
	string s1("Hello World!");       //用C格式的字符串构造string类对象s1
	string s2(s1);                       //拷贝构造s2
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

	s1.resize(5, 'x');                   //将字符串中有效字符个数改变到5个 当字 符个数增多时：resize(n)用0来填充多出的元素空间，resize(size_t n, char c)用字符c来填充多出的 元素空间。注意：resize在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大 小，如果是将元素个数减少，底层空间总大小不变。 
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

	s.reserve(50);                         //reserve只会向大调整
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