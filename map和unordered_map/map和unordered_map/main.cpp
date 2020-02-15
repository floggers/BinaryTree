#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	map<int, string> my_map = { {4,"张三"},{3,"李四"} };
	my_map[5] = "王二麻子";          //使用[]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
	//my_map[4] = "王五";
	my_map.insert(pair<int, string>(1, "陈二"));      //使用insert和pair插入
	for (auto & e : my_map) {
		cout << e.first << ' ' << e.second << endl;
	}

	cout << endl;

	unordered_map<int, string> my_unordered_map = { { 4,"张三" },{ 3,"李四" } };
	my_unordered_map[2] = "王二麻子";      //使用[]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
	//my_unordered_map[4] = "王五";
	my_unordered_map.insert(pair<int, string>(1, "陈二"));      //使用insert和pair插入
	for (auto & e : my_unordered_map) {
		cout << e.first << ' ' << e.second << endl;
	}
	system("pause");
	return 0;
}