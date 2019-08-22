#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

BTNode* BinaryTreeCreate(BTDataType* src) {        
  static int s_n = 0;                         //s_n:�±�
	if (src[s_n]=='#'){
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	s_n++;
	cur->_left = BinaryTreeCreate(src);
	cur->_right= BinaryTreeCreate(src);
	return cur;
}

void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);	
	}
}

void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);		
	}
}

void BinaryTreePostOrder(BTNode* root) {
	if (root){
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

void BinaryTreeDestory(BTNode* root) {                //��������  Ҳ��ǰ��������
	if (root) {
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
	}
}

void BinaryTreeLevelOrder(BTNode* root){             //�������
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu)){
		cur = QueueTop(&qu);              //ȡ�Ѷ�Ԫ��
		putchar(cur->_data);
		if (cur->_left){
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right){
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

int BinaryTreeSize(BTNode* root) {
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int n = 0;
	while (!QueueIsEmpty(&qu)) {
		cur = QueueTop(&qu);
		if (cur->_left) {
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right) {
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
		n++;
	}
	return n;
	QueueDestory(&qu);
}

int BinaryTreeLeafSize(BTNode* root) {
	int n = 0;
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu)) {
		cur = QueueTop(&qu);              //ȡ�Ѷ�Ԫ��
		if (cur->_left == NULL&&cur->_right == NULL) {
			n++;
		}
		 if (cur->_left) {
			QueuePush(&qu, cur->_left);
		}
		 if (cur->_right) {
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
	return n;
}

int BinaryTreeLevelKSize(BTNode* root, int k) {

}

void BinaryTreePrevOrderNonR(BTNode* root){      //�ǵݹ�ǰ����� 
	Stack st;                          // ����˼·: �����ǰ�ڵ�(һ��ʼΪ���ڵ�) 
	BTNode * cur = root;              //  �����Һ������Һ�����ջ ����������ָ������ û��������ȡ�Ѷ� ȡ��pop�� 
	StackInit(&st, 100);             // ���ѭ��ֱ��curΪnull
	while (cur){
		putchar(cur->_data);//���ʵ�ǰ�ڵ�
		if (cur->_right){ //������Һ�����ջ
			StackPush(&st, cur->_right);
		}

		if (cur->_left){//��������� ��������
			cur = cur->_left;
		}
		else{ //û��������ȡջ��
			cur = StackTop(&st);  //ȡ����ʱѭ������ ��������
			StackPop(&st);
		}
	}
	StackDestory(&st);
}


void BinaryTreeInOrderNonR(BTNode * root){     //�ǵݹ��������   
	BTNode * cur = root;                      //����˼·: �Ӹ��ڵ㿪ʼ�����������forѭ�� ���Ͻ����ڵ����������ջ
	Stack st;                                //Ȼ��ȡ(ָ��)ջ�� �����ھ����Ȼ��pop�� �̶�ָ�����Һ��� 
	StackInit(&st, 100);                    //���ѭ�� ֱ�� curΪnull��ջΪ��
	while (cur || !StackIsEmpty(&st)){
		for (cur=root; cur; cur = cur->_left){           //����ǰ�ڵ㼰��������ջ
			StackPush(&st, cur);
		}

		cur = StackTop(&st);                    //1.����Һ���Ϊ��,forѭ������ ֱ��ȡջ��)
		                                       //2.����Һ��Ӳ�Ϊ��,��ô����һ��û�����ӵĽڵ�
		                                      //��һ����� ������������� �ڶ������ ������Ϊ�� �������� ��ǰ�ڵ㶼Ҫ��ӡ
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;            //��������Ϊ��ʱ ���ջ�Ƿ�Ϊ�� ��ջҲΪ��ʱ ѭ������
		
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root){       //�������
	char tag[64];
	BTNode * cur = root;
	Stack st;
	StackInit(&st, 100);
	do {
		for (; cur; cur = cur->_left){  //��������,����ǰ�ڵ㼰��������ջ
			StackPush(&st, cur);
			tag[st.size - 1] = 0; //�������������ʱ��(LT)LeftTag
		}

		while (!StackIsEmpty(&st) && tag[st.size - 1]){  //ǰ�������ֻ�����һ��ѭ������ʱ��Ч
			   //�����ѭ�����������
			  //1.���˴�curΪ��ʱ,�����for����,����������
			 //2.��cur��Ϊ��,�����for��,�������������
			//�����⵽��ǰLT����λ(���1),��ô�ڴ�ӡ�굱ǰ�ڵ��,��ȥ�����һ���ڵ�(���ڵ�)�ǲ���ҲҪ����ӡ��(LT��λ,֤����������������,��ҲҪ����ӡ��)����Ҫ��whileѭ����ӡ
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}

		if (!StackIsEmpty(&st)){		//������ֻ�����һ��ѭ������ʱ��Ч	                   
			cur = StackTop(&st); 
			//1.��������while���� ��ô�����������������
			//2.��������whileû�� ��ô֤��������������
			//���Զ�Ҫ�������1
			tag[st.size - 1] = 1;
			cur = cur->_right; //������������Ϻ� ����������
		}
	} while (!StackIsEmpty(&st));//���ں�������и��ڵ�������ջ��,ջ������Ϊ��,������ջ�Ƿ�Ϊ�����ж��Ƿ������
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root) {                    //�ж��Ƿ�Ϊ��ȫ������
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int tag = 0;
	while (!QueueIsEmpty(&qu)) {          
		cur = QueueTop(&qu);                               //ȡ�Ѷ�Ԫ��
		if (cur->_right&&!cur->_left) {
			return 0;
		}
		if (tag==1&&(cur->_right || cur->_left)){
			return 0;
		}
		if (cur->_left) {
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right) {
			QueuePush(&qu, cur->_right);
		}
		else{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}