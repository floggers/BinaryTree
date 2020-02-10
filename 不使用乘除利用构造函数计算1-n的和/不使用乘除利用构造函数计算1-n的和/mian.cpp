#include <iostream>
using namespace std;

//方法一
class Sum{
private:
	static int n;
	static int sum;
public:
	Sum(){
		n++;
		sum += n;
	}

	static int ret(){
		return sum;
	}
};
int Sum::n = 0;
int Sum::sum = 0;

int s_sum(int n){
	Sum* p = new Sum[n];
	delete[]p;
	p = nullptr;

	//非静态成员只能用对象来调用，因此将ret()定义成静态成员函数
	return Sum::ret();
}


//方法二
class A{
public:
	virtual int sum(int n){               //出口
		return 0;
	}
};

A* a[2];       //指针数组

class B :public A{
public:
	virtual int sum(int n){              //递归
		return n + a[!!n]->sum(n - 1);
	}
};

int s_sum2(int n){
	A a1;
	B b1;
	a[0] = &a1;
	a[1] = &b1;

	//a[1]是父类的指针(而且子类完成了虚函数重新)，构成多态，当n不等于0时，调用
	//B::sum()，而且是递归的，递归时，当n等于0了，调用A::sum()即递归出口
	//这里的!!n起到了关键作用，当n==0时，a[!!n]==a[0],即父类指针指向父类对象，就会调用父类A::sum()
	int ret = a[1]->sum(n);
	return ret;
}


int main() {
	cout << s_sum(10) << endl;
	cout << s_sum2(11) << endl;
	system("pause");
	return 0;
}
