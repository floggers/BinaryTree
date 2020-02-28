#include <iostream>
using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
 		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}

	int jumpFloorII(int number) {                   //��̬������̨��  ������1-n��
		if (number <= 0) {
			return 0;
		}
		return 1 << (number - 1);                 //���ɾ��� f(n)=2^f(n-1)
	}

	int rectCover(int number) {
		int prepreRect = 1;
		int preRect = 2;
		int buf = 0;
		if (number == 1) {
			return 1;
		}
		else if (number == 2) {
			return 2;
		}
		else {
			for (int i = 3;i <= number;++i) {
				 buf = prepreRect + preRect;
				prepreRect = preRect;
				preRect = buf;
			}
		}
		return buf;
	}
};

int main() {
	Solution A;
	cout << A.jumpFloorII(4) << endl;
	cout << A.rectCover(6) << endl;
	system("pause");
	return 0;
}