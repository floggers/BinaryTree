#include <iostream>
using namespace std;

#if 1

class Solution {
public:
	int sum = 0;
	int tmp = 0;
	int Add(int num1, int num2) {
		if (num2 == 0) {
			return num1;
		}
		else {
			//��һ������Ӳ���λ  
			sum = num1 ^ num2;
			//�ڶ�������ý�λ��ֵ  
			tmp = (num1 & num2) << 1;
			//��������sum��tmp���  
			return Add(sum, tmp);
		}
	}
};

	int main() {
		Solution A;
		cout<<A.Add(5, 16)<<endl;
		system("pause");
		return 0;
	}

#endif