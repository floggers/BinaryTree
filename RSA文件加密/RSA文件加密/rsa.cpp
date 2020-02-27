#include "rsa.h"
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

RSA::RSA() {
	getKeys();
}

void RSA::Encrypt(const char* filename, const char* fileout) {          //fileout指的是输出格式
	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open()) {
		perror("input file open failed!");
		return;
	}
	char* buffer = new char[NUMBER];
	DataType* bufferout = new DataType[NUMBER];
	while (!fin.eof()) {
		fin.read(buffer, NUMBER);
		int curNmum = fin.gcount();
		for (int i = 0;i < curNmum;++i) {
			bufferout[i] = Encrypt((DataType)buffer[i], _key._ekey, _key._nkey);
		}
		fout.write((char*)bufferout, curNmum * sizeof(DataType));
	}
	delete[] buffer;
	delete[] bufferout;
	fin.close();
	fout.close();
}

void RSA::Decrypt(const char* filename, const char* fileout) {
	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open()) {
		perror("input file open failed!");
		return;
	}
	DataType* buffer = new DataType[NUMBER];
	char* bufferout = new char[NUMBER];
	while (!fin.eof()) {
		fin.read((char*)buffer, NUMBER * sizeof(DataType));
		int num = fin.gcount();
		num /= sizeof(DataType);
		for (int i = 0;i < num;++i) {
			bufferout[i] =(char) Decrypt(buffer[i], _key._dkey, _key._nkey);
		}
		fout.write(bufferout, num);
	}
	delete[] buffer;
	delete[] bufferout;
	fin.close();
	fout.close();
}

void RSA::getKeys() {
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2) {
		prime2 = getPrime();
	}
	DataType orla = getOrla(prime1, prime2);
	_key._nkey = getNkey(prime1, prime2);
	_key._ekey = getEkey(orla);
	_key._dkey = getDkey(_key._ekey, orla);
}

DataType RSA::getPrime() {
	cout << "getPrime()" << endl;
	//srand(time(NULL));
	boost::random::mt19937 gen(time(nullptr));
	boost::random::uniform_int_distribution<DataType> dist(0, DataType(1) << 256);
	DataType prime;

	while (true) {
	//	prime = rand() % 100 + 2;  // prime 2-101
		prime = dist(gen);
		if (isBigPrime(prime)) {
			break;
		}
	}
	cout << "get finish" << endl;
	return prime;
}

bool RSA::isPrime(DataType data) {

	if (data <= 0) {
		return false;
	}

	for (int i = 2;i <= sqrt(data);++i) {
		if (data%i == 0) {
			return false;
		}
	}
	return true;
}

bool RSA::isBigPrime(DataType data) {
	boost::random::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen)) {
		if (miller_rabin_test((data - 1) / 2, 25, gen)) {
			return true;
		}
	}
	return false;
}

DataType RSA::getGcd(DataType data1, DataType data2) {   //辗转相除法
	DataType residual;   //余数
	while (residual = data1%data2) {
		data1 = data2;
		data2 = residual;
	}
	return data2;
}

DataType RSA::getGcd_plus(DataType a, DataType b, DataType& x, DataType& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = getGcd_plus(b, a%b, x, y);
	DataType x1 = x;
	DataType y1 = y;
	x = y1;
	y = x1 - a / b*y1;
	return gcd;
}

DataType RSA::getNkey(DataType prime1, DataType prime2) {

	return prime1*prime2;

}

DataType RSA::getOrla(DataType prime1, DataType prime2) {

	return (prime1 - 1)*(prime2 - 1);

}

DataType RSA::getEkey(DataType orla) {
	srand(time(NULL));
	DataType ekey;
	while (true) {
		ekey = rand() % orla;
		if (ekey > 1 && getGcd(ekey, orla) == 1) {
			break;
		}
	}
	return ekey;
}

DataType RSA::getDkey(DataType ekey, DataType orla) {
	DataType x = 0;
	DataType y = 0;
	getGcd_plus(ekey, orla, x, y);
	return (x%orla + orla) % orla;

	//效率太低
	/*DataType dkey = orla / ekey;
	while (true) {
		if ((ekey*dkey) % orla == 1) {
			return dkey;
		}
		++dkey;
	}*/
}

DataType RSA::Encrypt(DataType data, DataType ekey, DataType nkey) {      //明文加密    //模幂运算   //使用pow()会导致数据溢出
																		  // A0=(a^((2^0)*1))) % c       // '1' 即为二进制中的 '1'  所以如果二进制位是'0'的话 A0就等于data本身 即 a
																		  // A(n-1)=(a^2^(n-1)) % c
																		  // An=(a^2^n) % c   所以An始终是A(n-1)的平方倍(未取模之前)   下面继续变形
																		  // An=(A(n-1)*A(n-1))% c
	DataType An = data;
	//加密后的数据msgE
	DataType msgE = 1;
	//data^ekey % nkey
	while (ekey) {
		if (ekey & 1) {
			msgE = (msgE*An) % nkey;
		}
		ekey >>= 1;  //ekey = ekey >> 1;	
		An = (An*An) % nkey;
	}
	return msgE;
}

DataType RSA::Decrypt(DataType data, DataType dkey, DataType nkey) {
	return Encrypt(data, dkey, nkey);
}

Key RSA::getallKeys() {
	return _key;
}