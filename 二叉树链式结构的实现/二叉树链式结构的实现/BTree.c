#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

BTNode* BinaryTreeCreate(BTDataType* src) {        
  static int s_n = 0;                         //s_n:下标
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

void BinaryTreeDestory(BTNode* root) {                //后序销毁  也可前中序销毁
	if (root) {
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
	}
}

void BinaryTreeLevelOrder(BTNode* root){             //层序遍历
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu)){
		cur = QueueTop(&qu);              //取堆顶元素
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
		cur = QueueTop(&qu);              //取堆顶元素
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

void BinaryTreePrevOrderNonR(BTNode* root){      //非递归前序遍历 
	Stack st;                          // 整体思路: 输出当前节点(一开始为根节点) 
	BTNode * cur = root;              //  若有右孩子则右孩子入栈 若有左孩子则指向左孩子 没有左孩子则取堆顶 取完pop掉 
	StackInit(&st, 100);             // 如此循环直到cur为null
	while (cur){
		putchar(cur->_data);//访问当前节点
		if (cur->_right){ //如果有右孩子入栈
			StackPush(&st, cur->_right);
		}

		if (cur->_left){//如果有左孩子 访问左孩子
			cur = cur->_left;
		}
		else{ //没有做孩子取栈顶
			cur = StackTop(&st);  //取到控时循环结束 程序跳出
			StackPop(&st);
		}
	}
	StackDestory(&st);
}


void BinaryTreeInOrderNonR(BTNode * root){     //非递归中序遍历   
	BTNode * cur = root;                      //整体思路: 从根节点开始用链表遍历的for循环 不断将根节点和其左孩子入栈
	Stack st;                                //然后取(指向)栈顶 若存在就输出然后pop掉 继而指向其右孩子 
	StackInit(&st, 100);                    //如此循环 直到 cur为null且栈为空
	while (cur || !StackIsEmpty(&st)){
		for (cur=root; cur; cur = cur->_left){           //将当前节点及左孩子们入栈
			StackPush(&st, cur);
		}

		cur = StackTop(&st);                    //1.如果右孩子为空,for循环不进 直接取栈顶)
		                                       //2.如果右孩子不为空,那么这是一个没有左孩子的节点
		                                      //第一种情况 左子树访问完毕 第二种情况 左子树为空 无论哪种 当前节点都要打印
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;            //当右子树为空时 检查栈是否为空 当栈也为空时 循环跳出
		
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root){       //后序遍历
	char tag[64];
	BTNode * cur = root;
	Stack st;
	StackInit(&st, 100);
	do {
		for (; cur; cur = cur->_left){  //类似中序,将当前节点及左孩子们入栈
			StackPush(&st, cur);
			tag[st.size - 1] = 0; //重置左子树访问标记(LT)LeftTag
		}

		while (!StackIsEmpty(&st) && tag[st.size - 1]){  //前面的条件只在最后一次循环跳出时生效
			   //后面的循环分两种情况
			  //1.当此次cur为空时,上面的for不进,此条件成立
			 //2.当cur不为空,上面的for进,则此条件不成立
			//如果检测到当前LT被置位(情况1),那么在打印完当前节点后,再去检查上一个节点(父节点)是不是也要被打印了(LT置位,证明这是他的右子树,他也要被打印了)所以要用while循环打印
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}

		if (!StackIsEmpty(&st)){		//此条件只在最后一次循环跳出时生效	                   
			cur = StackTop(&st); 
			//1.如果上面的while进了 那么整形最字数访问完毕
			//2.如果上面的while没进 那么证明左子树不存在
			//所以都要给标记置1
			tag[st.size - 1] = 1;
			cur = cur->_right; //左子树访问完毕后 访问右子树
		}
	} while (!StackIsEmpty(&st));//由于后序遍历中根节点是最后出栈的,栈不可能为空,所以以栈是否为空来判定是否出跳出
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root) {                    //判断是否为完全二叉树
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	int tag = 0;
	while (!QueueIsEmpty(&qu)) {          
		cur = QueueTop(&qu);                               //取堆顶元素
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