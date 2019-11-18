#include <iostream>
#include <algorithm>
using namespace std;

#if 0

class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b) {
			if (a > b) {
				a /= 2;
			}
			else {
				b /= 2;
			}
		}
		return a;
	}
};

int main() {
	LCA A;
	int a, b;
	cin >> a >> b;
	cout << A.getLCA(a, b);
	system("pause");
	return 0;
}

#endif

#if 1

int Max_continuous_num(int* arr,int n) {
	int sum = 0;
	int tmp1 = 0;
	//int tmp2 = 0;
	for (int i = 0;i < n;i++) {
		tmp1 += arr[i];
		if (sum == tmp1) {
			tmp1 = 0;
		}
		sum = tmp1 > sum ? tmp1 : sum;
	}
	return sum;
}


int main() {
	int num;
	int buf;
	int i = 0;
	int arr[32];
	cin >> num;
		while (num > 0) {
			buf = num % 2;
			arr[i] = buf;
			i++;
			num = num / 2;
		}
		cout << Max_continuous_num(arr, i);
	system("pause");
	return 0;
}

#endif

#if 0    //�ڶ���ڶ��ַ���
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n����32�ξͱ�Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
			{
				//���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxCount = max(count, maxCount);
			}
			else {
				//���1��ֵ�������������ۼ�
				count = 0;
			}
			//����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}

#endif