#include "rsa.h"
#include <iostream>
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

void tesrRSA() {
	RSA rsa;
	rsa.Encrypt("test.txt", "test.encrypt.txt");
	rsa.Decrypt("test.encrypt.txt", "test.decrypt.txt");
}

int main() {
	//test();
	tesrRSA();
	system("pause");
	return 0;
}