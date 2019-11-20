#include <iostream>
#include <string>
using namespace std;

#if 1

int main(){
	string str;
	int count = 0;
	while (getline(cin, str)) {
		//先整体遍历一遍
		for (size_t i = 0; i < str.size(); ++i) {
			//如果遇到空格，则先跳过，判断它下一位是不是引号?
			if (str[i] == ' ') {
				++i;
				if (str[i] == '\"' || str[i] == '\'') {
					//如果是引号则把引号的位置置换为\n，前面那个空格可以不管了
					//如果没有这条判断，则会把两个位置置换为\n.到时候输出的时候就				
					//会多一行空行
					str[i] = '\n';
					++count;
					--i;
					//遍历一直到下一个引号为止
					while (str[i] != '\"') {
						++i;
					}
					str[i] = '\0';
					//如果没有引号就将空格直接替换为\0
				}
				else {
					str[--i] = '\n';
					++count;
				}
			}
		}
		cout << count + 1 << endl;
		cout << str;
	}
	return 0;
}

#endif