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

#if 0    //第二题第二种方法
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n右移32次就变为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
			{
				//如果1的值连续，计数累加，并且跟新最大计数
				++count;
				maxCount = max(count, maxCount);
			}
			else {
				//如果1的值不连续，重新累加
				count = 0;
			}
			//右移一次，为获取下一位二进制值做准备
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}

#endif