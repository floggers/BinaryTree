#include<iostream>
using namespace std;
#define False 0
#define True 1
int Max[100][100] = { 0 };//各进程所需各类资源的最大需求
int Avaliable[100] = { 0 };//系统可用资源
char name[100] = { 0 };//资源的名称
int Allocation[100][100] = { 0 };//系统已分配资源
int Need[100][100] = { 0 };//还需要资源
int Request[100] = { 0 };//请求资源向量
int temp[100] = { 0 };//存放安全序列
int Work[100] = { 0 };//存放系统可提供资源
int M;//作业的最大数
int N;//资源的最大数
int Sum[50] = { 0 };

void Init() {
	int i, j, flag;
	char ming;
	cout << "请首先输入系统可供资源种类的数量:";
	cin >> N;
	for (i = 0;i < N;i++) {
		cout << "资源" << i + 1 << "的名称:";
		cin >> ming;
		name[i] = ming;
		cout << "资源的数量:";
		cin >> Sum[i];
	}
	cout << endl;
	cout << "请输入作业的数量:";
	cin >> M;
	cout << "请输入各进程的最大需求量(" << M << "*" << N << "矩阵)[Max]:" << endl;
	for (i = 0;i < M;i++)
		for (j = 0;j < N;j++)
			cin >> Max[i][j];
	do {
		flag = 0;
		cout << "请输入各进程已经申请的资源量(" << M << "*" << N << "矩阵)[Allocation]:" << endl;
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
		cout << "申请的资源大于最大需求量，请重新输入!\n";
	for (j = 0;j < N;j++) {
		for (i = 0;i < M;i++) {
			Sum[j] = Sum[j] - Allocation[i][j];
			Avaliable[j] = Sum[j];
		}
		cout << "Avaliable-" << name[j] << "的值：" << endl;
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

void Show_data() {           //显示资源矩阵
	int i, j;
	cout << "            Max      Allocation     Need" << endl;
	cout << "进程名     ";
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

int Change_data(int i) {                    //进行资源分配
	int j;
	for (j = 0;j < M;j++) {
		Avaliable[j] = Avaliable[j] - Request[j];
		Allocation[i][j] = Allocation[i][j] + Request[j];
		Need[i][j] = Need[i][j] - Request[j];
	}
	return 1;
}

int SAFE() {                                                    //安全性算法
	int i = 0, k = 0, m, apply, Finish[100] = { 0 };
	int j;
	Work[0] = Avaliable[0];
	Work[1] = Avaliable[1];
	Work[2] = Avaliable[2];
	for (i = 0;i < M;i++) {   //M进程数
		apply = 0;
		for (j = 0;j < N;j++) {      //N种类数
			if (Finish[i] == False&&Need[i][j] <= Work[j]) {
				apply++;
				if (apply == N) {
					for (m = 0;m < N;m++) {
						Work[m] = Work[m] + Allocation[i][m];//变分配数
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
			cout << "系统不安全" << endl;
			//不成功系统不安全回收*/
			return 0;
		}
	}
	cout << endl;
	cout << "系统是安全的!" << endl;//如果安全，输出成功
	cout << endl;
	cout << "分配的序列:";
	for (i = 0;i < M;i++) {                   //输出运行进程数组
		cout << temp[i];
		if (i < M - 1) cout << "->";
	}
	cout << endl;
	return 0;
}

void Share() {                       //利用银行家算法对申请资源对进行判定
	char ch;
	int i = 0, j = 0;
	ch = 'y';
	cout << "请输入要求分配的资源进程号(0-" << M - 1 << "):";
	cin >> i;                               //输入须申请的资源号
	cout << "请输入进程 " << i << " 申请的资源:" << endl;
	for (j = 0;j < N;j++) {
		cout << name[j] << ":";
		cin >> Request[j];                     //输入需要申请的资源
	}
	for (j = 0;j < N;j++) {
		if (Request[j] > Need[i][j]) {                 //判断申请是否大于需求，若大于则出错
			cout << "进程 " << i << "申请的资源大于它需要的资源";
			cout << " 分配不合理，不予分配！" << endl;
			ch = 'n';
			break;
		}
		else {
			if (Request[j] > Avaliable[j]) {                    //判断申请是否大于当前资源，若大于则出错
				cout << "进程" << i << "申请的资源大于系统现在可利用的资源";
				cout << " 分配出错，不予分配!" << endl;
				ch = 'n';
				break;
			}
		}
	}
	if (ch == 'y') {
		Change_data(i);//根据进程需求量变换资源
		Show_data();//根据进程需求量显示变换后的资源
					//SAFE();//根据进程需求量进行银行家算法判断
		if (SAFE() == -1)
			Restore(i);
	}
}

int main() {                         //主函数
	int choice;
	Init();                       //初始化
	Show_data();                  //显示各种资源
	SAFE();                    //用银行家算法判定系统是否安全
	while (1) {
		cout << endl;
		cout << "===============================================" << endl;
		cout << " ||              1 分配资源                 || " << endl;
		cout << " ||              0 离开                     ||" << endl;
		cout << "===============================================" << endl;
		cout << endl;
		cout << "请选择功能号：";
		cin >> choice;
		switch (choice) {
		case 1:Share();break;
		case 0:        break;
		default: cout << "请正确选择功能号(0-1)!" << endl;break;
		}
		if (choice == 0) {
			break;
		}
	}
	system("pause");
	return 0;
}





