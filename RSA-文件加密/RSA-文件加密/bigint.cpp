
#include "bigint.h"
#include <iostream>
#include <string>
using namespace std;

BigInt:: BigInt (const string& num) 
	:m_number(num)
{}
BigInt::BigInt(const char* num)
	: m_number(num)
{}
string BigInt::Add(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int dif = len1 - len2;
	if (dif < 0) {
		dif = len2 - len1;
		num1.insert(0, dif, '0');
	}
	else {
		num2.insert(0, dif, '0');
	}
	int step = 0;  //��λ
	for (int i = num1.size() - 1;i >= 0;--i) {
		num1[i] = (num1[i] - '0') + (num2[i] - '0') + step;
		if (num1[i] > 9) {
			num1[i] = num1[i] - 10 + '0';
			step = 1;
		}
		else {
			num1[i] = num1[i] + '0';
			step = 0;
		}
	}
	if (step) {
		num1.insert(0, "1");
	}
	return num1;
}

string BigInt::Sub(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	int dif = len1 - len2;
	num2.insert(0, dif, '0');
	for (int i = num1.size() - 1;i >= 1;--i) {
		num1[i] = (num1[i] - '0') - (num2[i] - '0');
		if (num1[i] >= 0) {
			num1[i] += '0';
		}
		else {
			num1[i] = num1[i] + 10 + '0';
			num1[i - 1] -= 1;
		}
	}
	if (num1[0] == num2[0]) {
		num1.erase(0, 1);         //ɾ����λ��0��ʼ��1��Ԫ��
	}
	else {
		num1[0] = (num1[0] - '0') - (num2[0] - '0') + '0';
	}
	while (num1[0] == '0'&&num1.size()>1) {
		num1.erase(0, 1);
	}
	return num1;
}


string BigInt::Mul(string num1, string num2) {                   //�����ӷ�
	if (!((num1[0] - '0')&&(num2[0]-'0'))) {
		return "0";
	}
	int len1 = num1.size();
	int len2 = num2.size();
	string buf1;
	string buf2;
	while (len2 >= 1) {
		int tmp = 0;
		int step = 0;
		for (int i = num1.size()-1;i >= 0;--i) {
			tmp = ((num1[i] - '0')*(num2[len2 - 1] - '0') + step) % 10;
			step= ((num1[i] - '0')*(num2[len2 - 1] - '0')) / 10;
			buf1 = to_string(tmp) + buf1;
		} 
		if (step) {
			buf1 = to_string(step) + buf1;
		}
			int dif = num2.size() - len2;
			buf1.append(dif, '0');
			buf2 = Add(buf1 , buf2);
	
		buf1.clear();
		len2--;
	}
	return buf2;
}

pair<string, string> BigInt::Dev(string num1, string num2) {                 //��������
	int len1 = num1.size();
	int len2 = num2.size();
	int dif = len1 - len2;
	num2.append(dif, '0');
	string ret;                 //��
	string rem;                //����
	char count = '0';
	int newLen = num2.size();
	while (newLen >= len2) {
		while (CompareString_greater(num1,num2)||num1 == num2) {
			num1 = Sub(num1, num2);
			++count;
		}
			num2.erase(newLen - 1, 1);
			--newLen;
			ret += count;
			count = '0';
	}
	while (ret[0] == '0'&& ret.size()>1) {
		ret.erase(0, 1);
	}
	rem = num1;
	return make_pair(ret, rem);
}

bool BigInt::CompareString_greater(string num1, string num2) {
	if (num1.size() > num2.size()) {
		return true;
	}
	else if (num1.size() < num2.size()) {
		return false;
	}
	else {         //������ͬʱ
		return num1 > num2;
	}
}

BigInt BigInt:: operator + (BigInt& bi) {
	string res = Add(m_number, bi.m_number);
	return BigInt(res);
}

BigInt BigInt::operator - (BigInt& bi) {
	string res = Sub(m_number, bi.m_number);
	return BigInt(res);
}

BigInt BigInt::operator * (BigInt& bi) {
	string res = Mul(m_number, bi.m_number);
	return BigInt(res);
}

BigInt BigInt::operator / (BigInt& bi) {
	pair<string, string> res = Dev(m_number, bi.m_number);
	return BigInt(res.first);
}

BigInt BigInt::operator % (BigInt& bi) {
	pair<string, string> res = Dev(m_number, bi.m_number);
	return BigInt(res.second);
}

ostream& operator<<(ostream&os, BigInt& bi) {
	os << bi.m_number;
	return os;
}