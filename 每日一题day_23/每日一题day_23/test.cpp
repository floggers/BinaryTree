#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int mid = gifts[n / 2];
		int count = 0;
		for (int i = 0;i < n;i++) {
			if (gifts[i] == mid) {
				count++;
			}
		}
		if (count > n / 2) {
			return mid;
		}
		return 0;
	}
};

int main() {
	Gift A;
	vector<int> v(5,1);
	cout << A.getValue(v, 5) << endl;
	system("pause");
	return 0;
}

#endif

#if 1


int main() {

	system("pause");
	return 0;
}

#endif