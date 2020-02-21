#include "rsa.h"
#include <time.h>
#include <iostream>

DataType RSA::getPrime() {

	srand(time(NULL));
	DataType prime;

	while (true) {
		prime = rand() % 100 + 2;  // prime 2-101
		if (isPrime(prime)) {
			return prime;
		}
	}

}

bool RSA:: isPrime(DataType data) {

	if (data <= 0) {
		return false;
	}

	for (int i = 2;i <= sqrt(data);++i) {
		if (data%i == 0) {
			return false;
		}
		return true;
	}
}

DataType RSA::getGcd(DataType data1, DataType data2) {   //辗转相除法
	DataType residual;   //余数
	while (residual = data1%data2) {
		data1 = data2;
		data2 = residual;
	}
	return data2;
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
			return ekey;
		}
	}

}