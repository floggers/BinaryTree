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