#pragma once
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#define NUMBER 256
//typedef long DataType;
typedef boost::multiprecision::int1024_t DataType;

struct Key {
	//(e,n)  (d,n)
	DataType _ekey;
	DataType _dkey;
	DataType _nkey;
};

class RSA {
private:
	Key _key;
public:
	RSA();
	void Encrypt(const char* filename, const char* fileout);   //fileout指的是输出格式
	void Decrypt(const char* filename, const char* fileout);

	DataType getPrime();

	bool isPrime(DataType data);
	bool isBigPrime(DataType data);

	DataType getGcd(DataType data1, DataType data2);  //GCD->Greatest Common Divisor最大公约数
	DataType getGcd_plus(DataType a, DataType b, DataType& x, DataType& y);
	DataType getNkey(DataType prime1, DataType prime2);
	DataType getOrla(DataType prime1, DataType prime2);
	DataType getEkey(DataType orla);
	DataType getDkey(DataType ekey, DataType orla);
	DataType Encrypt(DataType data, DataType ekey, DataType nkey);
	DataType Decrypt(DataType data, DataType dkey, DataType nkey);


	void getKeys();
	Key getallKeys();
};