#include <iostream>
using namespace std;

typedef union{
	int a;
	char c;
}A;

int main(){
	A myunion;
	myunion.a = 1;
	if (myunion.c == 1)         //����ch��ֵ�ж�ϵͳ��С��
	{
		printf("ϵͳΪС�˴洢!\n");
	}
	else
	{
		printf("ϵͳΪ��˴洢!\n");
	}
system("pause");
return 0;
}