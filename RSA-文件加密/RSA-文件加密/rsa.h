#pragma once

typedef long DataType;

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
	DataType getPrime();
	bool isPrime(DataType data);
	DataType getGcd(DataType data1, DataType data2);  //GCD->Greatest Common Divisor最大公约数
	DataType getNkey(DataType prime1, DataType prime2);
	DataType getOrla(DataType prime1, DataType prime2);
	DataType getEkey(DataType orla);
	DataType getDkey(DataType ekey, DataType orla);
	DataType getEncrypt(DataType data, DataType ekey, DataType nkey);
	DataType getDecrypt(DataType data, DataType dkey, DataType nkey);
};