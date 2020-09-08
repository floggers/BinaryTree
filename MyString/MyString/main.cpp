#include <iostream>
using namespace std;

class String {
private:
	char* _str;
public:
	const char* get_str() {
		return _str;
	}

	String(const char* str=nullptr)
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

	friend String operator+(const String& s1, const String& s2) {
		char* p = new char[strlen(s1._str) + strlen(s2._str) + 1];
		strcpy(p, s1._str);
		strcat(p, s2._str);
		String tmp(p);
		delete[] p;
		return tmp;
	}

	String& operator+=(const String& s) {
		char* p = new char[strlen(_str) + strlen(s._str) + 1];
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
	String s1("chua ");
	String s2="xiu xiu~ ";
	String s3 = s2;
	String s4 = s1 + s2;
	String s5 = "haiya " + s1;
	String s6 = s2 + "peng peng~";
	s4 += "778";
	/*cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s1.get_str() << endl;
	cout << s2.get_str() << endl;
	cout << s3 << endl;
	cout << s4[1] << endl;*/
	if (s2 <= s3) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	system("pause");
	return 0;
}