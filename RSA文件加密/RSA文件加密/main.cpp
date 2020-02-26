#include "rsa.h"
#include "bigint.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>
using namespace std;

void test() {
	RSA rsa;
	rsa.getKeys();
	Key key = rsa.getallKeys();
	DataType original = 2;
	cout << "original: " << original << endl;
	cout << key._ekey << " " << key._dkey << " " << key._nkey << endl;
	cout << rsa.Encrypt(original, key._ekey, key._nkey) << endl;
	cout << rsa.Decrypt(original, key._dkey, key._nkey) << endl;
}

void testRSA() {
	RSA rsa;
	rsa.Encrypt("test.txt", "test.encrypt.txt");
	rsa.Decrypt("test.encrypt.txt", "test.decrypt.txt");
}

void testBigIntAdd() {
	//BigInt A;
	int a = 1;
	int b = 1;
	cout << a + b << endl;
	//cout << A.Add("9234353", "876456") << endl;
	BigInt A("1");
	BigInt B("1");
	cout << A + B << endl;
}

void testBigIntASub() {
	//BigInt A;
	int a = 5;
	int b = 5;
	cout << a - b << endl;
	//cout << A.Sub("1001", "999") << endl;
	BigInt A("5");
	BigInt B("5");
	cout << A - B << endl;
}

void testBigIntMul() {
	//BigInt A;
	int a = 10000;
	int b = 10;
	cout << a * b << endl;
	//cout << A.Mul("10000", "10") << endl;
	BigInt A("10000");
	BigInt B("10");
	cout << A * B << endl;
}

void testBigIntDev() {
	//BigInt A;
	int a = 1235425543;
	int b = 876456;

	cout << a / b << "  " << a % b << endl;
	//cout << A.Dev(str1, str2).first << "  " << A.Dev(str1, str2).second << endl;
	BigInt A("1235425543");
	BigInt B("876456");
	cout << A / B << "  " << A % B << endl;
}

void testBoostBigInt() {
	boost::multiprecision::cpp_int ci;
	//常量太多
	//ci = 124236428375354366666666663415413771474858365246523862535;
	ci = 123212532676571512; 
	cout << ci << endl;

	string num = "124236428375354366666666663415413771474858365246523862535";
	boost::multiprecision::cpp_int str_num(num);   //位数不固定
	cout << str_num << endl;
	cout << str_num + 1 << endl;

	boost::multiprecision::int1024_t num_1024(num);  //1024位
	cout << num_1024 << endl;
	cout << num_1024 + 1 << endl;

	boost::multiprecision::int1024_t num_1024_2 = boost::multiprecision::int1024_t(1) << 1023;   //1左移1023位
	cout << num_1024_2 << endl;
}

int main() {
	//test();
	testRSA();
	//testBigIntAdd();
	//testBigIntASub();
	//testBigIntMul();
	//testBigIntDev();
	//testBoostBigInt();
	system("pause");
	return 0;
}