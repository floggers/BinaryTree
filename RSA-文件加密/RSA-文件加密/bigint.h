#pragma once
#include <string>
using namespace std;

class BigInt {
public:
	BigInt() {}
	~BigInt() {}
	string m_number;
	string Add(string num1, string num2);
	string Sub(string num1, string num2);
	string Mul(string num1, string num2);
	pair<string,string> Dev(string num1, string num2);
	bool CompareString_greater(string num1, string num2);

	//BigInt(const string& num);
	//BigInt(const int num);
};