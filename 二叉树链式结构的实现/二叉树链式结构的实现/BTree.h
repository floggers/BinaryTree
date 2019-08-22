#ifndef  _BTree_H_
#define  _BTree_H_

typedef char BTDataType;
typedef struct BinaryTreeNode { 
	BTDataType _data;   
	struct BinaryTreeNode* _left;    
	struct BinaryTreeNode* _right;  
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* src);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);                  //�ڵ����
int BinaryTreeLeafSize(BTNode* root);              //Ҷ�Ӹ���
int BinaryTreeLevelKSize(BTNode* root, int k);   //��k��Ľڵ���
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ���� 
void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);
// �ǵݹ���� 
// �������
void BinaryTreeLevelOrder(BTNode* root); 
// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root); 
void BinaryTreeInOrderNonR(BTNode* root); 
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif 
