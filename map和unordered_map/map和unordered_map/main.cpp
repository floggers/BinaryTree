#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	map<int, string> my_map = { {4,"����"},{3,"����"} };
	my_map[5] = "��������";          //ʹ��[]���е������룬���Ѵ��ڼ�ֵ2����ֵ�޸ģ���������롣
	//my_map[4] = "����";
	my_map.insert(pair<int, string>(1, "�¶�"));      //ʹ��insert��pair����
	for (auto & e : my_map) {
		cout << e.first << ' ' << e.second << endl;
	}

	cout << endl;

	unordered_map<int, string> my_unordered_map = { { 4,"����" },{ 3,"����" } };
	my_unordered_map[2] = "��������";      //ʹ��[]���е������룬���Ѵ��ڼ�ֵ2����ֵ�޸ģ���������롣
	//my_unordered_map[4] = "����";
	my_unordered_map.insert(pair<int, string>(1, "�¶�"));      //ʹ��insert��pair����
	for (auto & e : my_unordered_map) {
		cout << e.first << ' ' << e.second << endl;
	}
	system("pause");
	return 0;
}