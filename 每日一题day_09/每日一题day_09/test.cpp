#include <iostream>
#include <vector>
using namespace std;

#if 0

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


#if 1

	int Total_ways(int n, int m) {
		int ways = 0;
		vector<vector<int>> vi;
		vi.resize(n+1);
		for (int i = 0;i <=n;i++) {
			vi[i].resize(m+1,1);
		}
		for (int i = 0;i <= n;i++) {
			for (int j = 0;j <= m;j++) {
				if (j - 1 >= 0 && i - 1 >= 0) {
					vi[i][j] = vi[i][j - 1] + vi[i - 1][j];
				}
			}
		}
		ways = vi[n][m];
		return ways;
	}

	int main() {
		int a, b;
		cin >> a >> b;
		cout << Total_ways(a, b) << endl;
		system("pause");
		return 0;
	}
#endif