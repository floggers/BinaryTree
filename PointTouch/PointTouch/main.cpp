#include <iostream>

using namespace std;


class LittleGame {
private:
	bool walk, attack, defend;
public:
	LittleGame()
		:walk(true),
		 attack(false),
		 defend(false) {
	}
	void print() {
		cout << "��ӭ����ð�ռ���԰��" << endl;
		cout << "��Ϸ��ʾ��" << endl;
		cout << "���㴦������״̬ʱ,����A���빥��״̬������B�������״̬" << endl;
		cout << "���㴦�ڹ���״̬ʱ,����A��������״̬������B�������״̬" << endl;
		cout << "���㴦�ڷ���״̬ʱ,����A���빥��״̬������B��������״̬" << endl;
		cout << endl;
	}
	void init() {
		if (walk) {
			cout << "**Ŀǰ�㴦������״̬**" << endl;
			cout << "��������һ����Ҫ�任����̬��" << endl;
		}
		if (attack) {
			cout << "**Ŀǰ�㴦�ڹ���״̬**" << endl;
			cout << "��������һ����Ҫ�任����̬��" << endl;
		}
		if (defend) {
			cout << "**Ŀǰ�㴦�ڷ���״̬**" << endl;
			cout << "��������һ����Ҫ�任����̬��" << endl;
		}
	}
	void play(char button) {
		if (walk) {
			if (button == 'A') {
				walk = false;
				attack = true;
			}
			if (button == 'B') {
				walk = false;
				defend = true;
			}
		}
		else if (attack) {
			if (button == 'A') {
				attack = false;
				walk = true;
			}
			if (button == 'B') {
				attack = false;
				defend = true;
			}
		}
		else if (defend) {
			if (button == 'A') {
				defend = false;
				attack = true;
			}
			if (button == 'B') {
				defend = false;
				walk = true;
			}
		}
	}
};

int main() {
	LittleGame test;
	test.print();
	while (1) {
		test.init();
		char button;
		cin >> button;
		test.play(button);
	}
	system("pause");
	return 0;
}