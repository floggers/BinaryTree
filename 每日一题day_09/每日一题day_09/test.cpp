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
			//第一步，相加不进位  
			sum = num1 ^ num2;
			//第二步，求得进位的值  
			tmp = (num1 & num2) << 1;
			//第三步，sum和tmp相加  
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