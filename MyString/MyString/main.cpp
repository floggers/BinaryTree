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

	String& operator=(const String& s) {    //"="ÔËËã·ûÖØÔØ
		if (this != &s) {
			String tmp(s._str);
			swap(this->_str, tmp._str);
			return *this;
		}
	}

	String operator+(const String& s) {
		char* p = new char(strlen(_str) + strlen(s._str) + 1);
		strcpy(p, _str);
		strcat(p, s._str);
		String tmp(p);
		delete[] p;
		return tmp;
	}

	String& operator+=(const String& s) {
		char* p = new char(strlen(_str) + strlen(s._str) + 1);
		strcpy(p, _str);
		strcat(p, s._str);
		delete[] _str;
		_str = p;
		return *this;
	}

	bool operator==(const String& s) {
		return strcmp(_str, s._str) == 0;
	}

	bool operator!=(const String& s) {
		return strcmp(_str, s._str) != 0;
	}

	bool operator>=(const String& s) {
		return strcmp(_str, s._str) >= 0;
	}

	bool operator<=(const String& s) {
		return strcmp(_str, s._str) <= 0;
	}

	bool operator>(const String& s) {
		return strcmp(_str, s._str) > 0;
	}

	bool operator<(const String& s) {
		return strcmp(_str, s._str) < 0;
	}

	char& operator[](int index) {
		return _str[index];
	}

	friend ostream& operator<<(ostream& os, const String& s) {
		os << s._str;
		return os;
	}

	friend iostream& operator>>(iostream& is, String& s) {
		is >> s._str;
		return is;
	}

	~String() {
		if (_str) {
			delete[] _str;
			_str = NULL;
		}
	}
};

int main() {
	String s1("chua£¡");
	String s2(s1);
	String s3 = s2;
	cout << s1.get_str() << endl;
	cout << s2.get_str() << endl;
	cout << s3 << endl;
	cout << s3[1] << endl;
	system("pause");
	return 0;
}