#include "BTree.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);	
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');
	BinaryTreeLevelOrder(root);
	putchar('\n');
    printf("TreeSize is %d", BinaryTreeSize( root));
	putchar('\n');
	printf("LeafSize is %d", BinaryTreeLeafSize(root));
	putchar('\n');
	printf("%d",BinaryTreeComplete(root));
	putchar('\n');
	BinaryTreeDestory(root);
	system("pause");
		return 0;
}