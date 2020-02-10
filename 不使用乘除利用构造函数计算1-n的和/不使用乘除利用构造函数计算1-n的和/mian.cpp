#include <iostream>
using namespace std;

//����һ
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

	//�Ǿ�̬��Աֻ���ö��������ã���˽�ret()����ɾ�̬��Ա����
	return Sum::ret();
}


//������
class A{
public:
	virtual int sum(int n){               //����
		return 0;
	}
};

A* a[2];       //ָ������

class B :public A{
public:
	virtual int sum(int n){              //�ݹ�
		return n + a[!!n]->sum(n - 1);
	}
};

int s_sum2(int n){
	A a1;
	B b1;
	a[0] = &a1;
	a[1] = &b1;

	//a[1]�Ǹ����ָ��(��������������麯������)�����ɶ�̬����n������0ʱ������
	//B::sum()�������ǵݹ�ģ��ݹ�ʱ����n����0�ˣ�����A::sum()���ݹ����
	//�����!!n���˹ؼ����ã���n==0ʱ��a[!!n]==a[0],������ָ��ָ������󣬾ͻ���ø���A::sum()
	int ret = a[1]->sum(n);
	return ret;
}


int main() {
	cout << s_sum(10) << endl;
	cout << s_sum2(11) << endl;
	system("pause");
	return 0;
}
