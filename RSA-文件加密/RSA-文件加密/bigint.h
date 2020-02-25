#pragma once
#include <string>
#include <iostream>
using namespace std;

class BigInt {
private:
	string m_number;
	string Add(string num1, string num2);
	string Sub(string num1, string num2);
	string Mul(string num1, string num2);
	pair<string,string> Dev(string num1, string num2);
	bool CompareString_greater(string num1, string num2);
public:
	BigInt operator + (BigInt& bi);
	BigInt operator - (BigInt& bi);
	BigInt operator * (BigInt& bi);
	BigInt operator / (BigInt& bi);
	BigInt operator % (BigInt& bi);
	friend ostream& operator<<(ostream& _cout, BigInt& bi);
	BigInt(){}
	BigInt(const string& num);
	BigInt(const char* num);
	//BigInt(const int num);
};


