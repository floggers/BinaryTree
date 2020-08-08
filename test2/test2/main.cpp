#include <iostream>
using namespace std;

typedef union{
	int a;
	char c;
}A;

int main(){
	A myunion;
	myunion.a = 1;
	if (myunion.c == 1)         //根据ch的值判断系统大小端
	{
		printf("系统为小端存储!\n");
	}
	else
	{
		printf("系统为大端存储!\n");
	}
system("pause");
return 0;
}