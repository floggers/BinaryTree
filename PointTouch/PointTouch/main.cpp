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
		cout << "欢迎来到冒险家乐园！" << endl;
		cout << "游戏提示：" << endl;
		cout << "当你处于行走状态时,输入A进入攻击状态，输入B进入防御状态" << endl;
		cout << "当你处于攻击状态时,输入A进入行走状态，输入B进入防御状态" << endl;
		cout << "当你处于防御状态时,输入A进入攻击状态，输入B进入行走状态" << endl;
		cout << endl;
	}
	void init() {
		if (walk) {
			cout << "**目前你处于行走状态**" << endl;
			cout << "请输入下一个想要变换的形态：" << endl;
		}
		if (attack) {
			cout << "**目前你处于攻击状态**" << endl;
			cout << "请输入下一个想要变换的形态：" << endl;
		}
		if (defend) {
			cout << "**目前你处于防御状态**" << endl;
			cout << "请输入下一个想要变换的形态：" << endl;
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