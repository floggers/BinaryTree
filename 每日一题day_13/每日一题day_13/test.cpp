#include <iostream>
#include <string>
using namespace std;

#if 1

int main(){
	string str;
	int count = 0;
	while (getline(cin, str)) {
		//���������һ��
		for (size_t i = 0; i < str.size(); ++i) {
			//��������ո������������ж�����һλ�ǲ�������?
			if (str[i] == ' ') {
				++i;
				if (str[i] == '\"' || str[i] == '\'') {
					//���������������ŵ�λ���û�Ϊ\n��ǰ���Ǹ��ո���Բ�����
					//���û�������жϣ���������λ���û�Ϊ\n.��ʱ�������ʱ���				
					//���һ�п���
					str[i] = '\n';
					++count;
					--i;
					//����һֱ����һ������Ϊֹ
					while (str[i] != '\"') {
						++i;
					}
					str[i] = '\0';
					//���û�����žͽ��ո�ֱ���滻Ϊ\0
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