#include "rsa.h"
#include "bigint.h"
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

void testBigIntAdd(){
	BigInt A;
	int a = 9234353;
	int b = 876456;
	cout << a + b << endl;
	cout << A.Add("9234353", "876456") << endl;
}

void testBigIntASub() {
	BigInt A;
	int a = 1001;
	int b = 999;
	cout << a - b << endl;
	cout << A.Sub("1001", "999") << endl;
}

void testBigIntMul() {
	BigInt A;
	int a = 10000;
	int b = 10;
	cout << a * b << endl;
	cout << A.Mul("10000", "10") << endl;
}

void testBigIntDev() {
	BigInt A;
	int a = 1235425543;
	int b = 183344;
	cout << a / b << "  " << a % b << endl;
	cout << A.Dev("1235425543", "183344").first << "  " << A.Dev("1235425543", "183344").second << endl;
}

int main() {
	//test();
	//testRSA();
	//testBigIntAdd();
	//testBigIntASub();
	//testBigIntMul();
    testBigIntDev();
	system("pause");
	return 0;
}