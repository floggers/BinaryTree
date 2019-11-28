#include <iostream>
#include <string>
using namespace std;

#if 0

void reverse_str( char* begin, char* end) {
	while (begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

int main() {
	char str1[100] = { 0 };
	int i = 0;
	while (1) {
		str1[i] = getchar();
		if (str1[i] == '\n') {
			str1[i] = '\0';
			break;
		}
		i++;
	}
	reverse_str(str1,str1+strlen(str1)-1);
	cout << str1 << endl;
	system("pause");
	return 0;
}

#endif

#if 1



int main()
#endif