#include <iostream>
using namespace std;

class String {
private:
	char* _str;
public:
	const char* get_str() {
		return _str;
	}

	String(const char* str)
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(NULL)
	{
		String tmp(s._str);
		swap(this->_str, tmp._str);
	}

	String& operator=(const String& s) {    //"="运算符重载
		if (this != &s) {
			String tmp(s._str);
			swap(this->_str, tmp._str);
			return *this;
		}
	}

	friend ostream& operator<<(ostream& os, const String& s) {
		os << s._str;
		return os;
	}

	~String() {
		if (_str) {
			delete[] _str;
		}
	}
};

int main() {
	String s1("天霸动霸chua！");
	String s2(s1);
	String s3 = s2;
	cout << s1.get_str() << endl;
	cout << s2.get_str() << endl;
	cout << s3 << endl;
	system("pause");
	return 0;
}