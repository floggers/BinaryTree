#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//����1 ��Խ��
int Fib(int n) {
	 if (n == 0) {
		return 0;
	}
	 else if (n == 1) {
		return 1;
	}
	 else if (n == 2) {
		 return 2;
	 }
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main() {
	int n;
	cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
			printf("%04d", Fib(v[i]) % 10000);
		}
		cout << endl;
	system("pause");
	return 0;
}

#endif

#if 0
//����2
int main(){
	int f[10001];
	for (int i = 2; i < 10001; i++){
		f[0] = 1;
		f[1] = 1;
		f[i] = (f[i - 1] % 10000 + f[i - 2] % 10000) % 10000;
	}
	int n;
	while (cin >> n){
		while (n--){
			int x;
			cin >> x;
			printf("%04d", f[x]);
		}
		cout << endl;
	}
	return 0;
}

#endif

#if 1

int Tree_root(int num) {
	int tmp = 0;
	if (num < 10) {
		return num;
	}
	else {
		tmp = num % 10;
		return Tree_root(Tree_root(tmp % 10) + Tree_root(num / 10));
	}
}

int main() {
	string num;
	int tmp;
	int buf = 0;
	while (cin >> num) {
		buf = 0;
		for (auto i : num) {
			buf += i - '0';
		}
		tmp = Tree_root(buf);
		cout << tmp<<endl;
	}
	system("pause");
	return 0;
}

#endif

#if 0
int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		nroot += num % 10;
		num /= 10;
	}
	//������������ر�����д��Ϊif,һ��Ҫ��while��
	//��Ϊ����ǵݹ飬return ���ص�ʱ�򲢲�һ�����˳���ֻ�Ƿ��ص�
	//��һ�㺯���ĵ��õ�ĩβ
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}

int main() {
	string origin;
	while (cin >> origin) {
		int sum = 0;
		//�Ƚ�ÿһλ������ӵõ��ܺͣ���ֹ���ֹ���
		//���������󣬻��˷Ѵ�����ʱ��ȥ����ÿһλ������
		//������������һ���򵥵��Ż�
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//���ܺ�������
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}

#endif