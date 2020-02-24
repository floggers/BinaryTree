#pragma once
#include <string>
#include <utility>
using namespace std;

class BigInt {
public:
	BigInt() {}
	string m_number;
	string Add(string num1, string num2);
	string Sub(string num1, string num2);
	string Mul(string num1, string num2);
	pair<string,string> Dev(string num1, string num2);

	BigInt(const string& num);
	BigInt(const int num);
};