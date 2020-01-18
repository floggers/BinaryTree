#include<iostream>
using namespace std;
#define False 0
#define True 1
int Max[100][100] = { 0 };//���������������Դ���������
int Avaliable[100] = { 0 };//ϵͳ������Դ
char name[100] = { 0 };//��Դ������
int Allocation[100][100] = { 0 };//ϵͳ�ѷ�����Դ
int Need[100][100] = { 0 };//����Ҫ��Դ
int Request[100] = { 0 };//������Դ����
int temp[100] = { 0 };//��Ű�ȫ����
int Work[100] = { 0 };//���ϵͳ���ṩ��Դ
int M;//��ҵ�������
int N;//��Դ�������
int Sum[50] = { 0 };

void Init() {
	int i, j, flag;
	char ming;
	cout << "����������ϵͳ�ɹ���Դ���������:";
	cin >> N;
	for (i = 0;i < N;i++) {
		cout << "��Դ" << i + 1 << "������:";
		cin >> ming;
		name[i] = ming;
		cout << "��Դ������:";
		cin >> Sum[i];
	}
	cout << endl;
	cout << "��������ҵ������:";
	cin >> M;
	cout << "����������̵����������(" << M << "*" << N << "����)[Max]:" << endl;
	for (i = 0;i < M;i++)
		for (j = 0;j < N;j++)
			cin >> Max[i][j];
	do {
		flag = 0;
		cout << "������������Ѿ��������Դ��(" << M << "*" << N << "����)[Allocation]:" << endl;
		for (i = 0;i < M;i++)
			for (j = 0;j < N;j++)
			{
				cin >> Allocation[i][j];
				if (Allocation[i][j] > Max[i][j])
					flag = 1;
				Need[i][j] = Max[i][j] - Allocation[i][j];
			}
	} while (flag);
	if (flag)
		cout << "�������Դ�������������������������!\n";
	for (j = 0;j < N;j++) {
		for (i = 0;i < M;i++) {
			Sum[j] = Sum[j] - Allocation[i][j];
			Avaliable[j] = Sum[j];
		}
		cout << "Avaliable-" << name[j] << "��ֵ��" << endl;
		cout << Avaliable[j] << endl;
	}
	cout << endl;
}

void Restore(int i) {
	int j;
	for (j = 0;j < N;j++) {
		Avaliable[j] = Avaliable[j] + Request[j];
		Allocation[i][j] = Allocation[i][j] - Request[j];
		Need[i][j] = Need[i][j] + Request[j];
	}
}

void Show_data() {           //��ʾ��Դ����
	int i, j;
	cout << "            Max      Allocation     Need" << endl;
	cout << "������     ";
	for (j = 0;j < 3;j++) {
		for (i = 0;i < N;i++)
			cout << name[i] << " ";
		cout << "      ";
	}
	cout << endl;
	for (i = 0;i < M;i++) {
		cout << " " << i << "         ";
		for (j = 0;j < N;j++)
			cout << Max[i][j] << " ";
		cout << "      ";
		for (j = 0;j < N;j++)
			cout << Allocation[i][j] << " ";
		cout << "      ";
		for (j = 0;j < N;j++)
			cout << Need[i][j] << " ";
		cout << endl;
	}
}

int Change_data(int i) {                    //������Դ����
	int j;
	for (j = 0;j < M;j++) {
		Avaliable[j] = Avaliable[j] - Request[j];
		Allocation[i][j] = Allocation[i][j] + Request[j];
		Need[i][j] = Need[i][j] - Request[j];
	}
	return 1;
}

int SAFE() {                                                    //��ȫ���㷨
	int i = 0, k = 0, m, apply, Finish[100] = { 0 };
	int j;
	Work[0] = Avaliable[0];
	Work[1] = Avaliable[1];
	Work[2] = Avaliable[2];
	for (i = 0;i < M;i++) {   //M������
		apply = 0;
		for (j = 0;j < N;j++) {      //N������
			if (Finish[i] == False&&Need[i][j] <= Work[j]) {
				apply++;
				if (apply == N) {
					for (m = 0;m < N;m++) {
						Work[m] = Work[m] + Allocation[i][m];//�������
						Finish[i] = True;
					}
					temp[k] = i;
					i = -1;
					k++;
				}
			}
		}
	}
	for (i = 0;i < M;i++) {
		if (Finish[i] == False) {
			cout << endl;
			cout << "ϵͳ����ȫ" << endl;
			//���ɹ�ϵͳ����ȫ����*/
			return 0;
		}
	}
	cout << endl;
	cout << "ϵͳ�ǰ�ȫ��!" << endl;//�����ȫ������ɹ�
	cout << endl;
	cout << "���������:";
	for (i = 0;i < M;i++) {                   //������н�������
		cout << temp[i];
		if (i < M - 1) cout << "->";
	}
	cout << endl;
	return 0;
}

void Share() {                       //�������м��㷨��������Դ�Խ����ж�
	char ch;
	int i = 0, j = 0;
	ch = 'y';
	cout << "������Ҫ��������Դ���̺�(0-" << M - 1 << "):";
	cin >> i;                               //�������������Դ��
	cout << "��������� " << i << " �������Դ:" << endl;
	for (j = 0;j < N;j++) {
		cout << name[j] << ":";
		cin >> Request[j];                     //������Ҫ�������Դ
	}
	for (j = 0;j < N;j++) {
		if (Request[j] > Need[i][j]) {                 //�ж������Ƿ�������������������
			cout << "���� " << i << "�������Դ��������Ҫ����Դ";
			cout << " ���䲻����������䣡" << endl;
			ch = 'n';
			break;
		}
		else {
			if (Request[j] > Avaliable[j]) {                    //�ж������Ƿ���ڵ�ǰ��Դ�������������
				cout << "����" << i << "�������Դ����ϵͳ���ڿ����õ���Դ";
				cout << " ��������������!" << endl;
				ch = 'n';
				break;
			}
		}
	}
	if (ch == 'y') {
		Change_data(i);//���ݽ����������任��Դ
		Show_data();//���ݽ�����������ʾ�任�����Դ
					//SAFE();//���ݽ����������������м��㷨�ж�
		if (SAFE() == -1)
			Restore(i);
	}
}

int main() {                         //������
	int choice;
	Init();                       //��ʼ��
	Show_data();                  //��ʾ������Դ
	SAFE();                    //�����м��㷨�ж�ϵͳ�Ƿ�ȫ
	while (1) {
		cout << endl;
		cout << "===============================================" << endl;
		cout << " ||              1 ������Դ                 || " << endl;
		cout << " ||              0 �뿪                     ||" << endl;
		cout << "===============================================" << endl;
		cout << endl;
		cout << "��ѡ���ܺţ�";
		cin >> choice;
		switch (choice) {
		case 1:Share();break;
		case 0:        break;
		default: cout << "����ȷѡ���ܺ�(0-1)!" << endl;break;
		}
		if (choice == 0) {
			break;
		}
	}
	system("pause");
	return 0;
}





